
#include <algorithm>
#include <cmath>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>

#include "idea.h"
#include "model.h"

#define IDEA_MODEL_INIT(model)                                              \
  std::string model##_errlev = DEFAULT_ERROR_LEVEL;                         \
  if (accuracy_info.find("ALL") != accuracy_info.end())                     \
    model##_errlev = accuracy_info.find("ALL")->second;                     \
  if (accuracy_info.find(#model) != accuracy_info.end())                    \
    model##_errlev = accuracy_info.find(#model)->second;                    \
  model = std::make_shared<Model>();                                        \
  const bool model##_init =                                                 \
      model->Init(header + #model "_" + model##_errlev + "p.dat");          \
  string_buffer += (#model " " + model##_errlev + "% accuracy");            \
  if (model##_init)                                                         \
    string_buffer += " (INIT SUCCESS) -> " +                                \
                     std::to_string(model->GetAccuracy()) + "% accuracy\n"; \
  else                                                                      \
    string_buffer += " (INIT FAILURE)\n"

namespace IDEA_internal {
std::vector<std::string> SplitString(const std::string& str,
                                     const char delimiter) {
  std::vector<std::string> toks;
  std::stringstream ss(str);
  std::string tok;
  while (std::getline(ss, tok, delimiter)) toks.push_back(tok);
  if (str.back() == delimiter) toks.push_back("");
  return toks;
}
void RemoveString(std::string& str, const std::vector<char>& drops) {
  for (auto&& it = drops.begin(); it < drops.end(); it++)
    str.erase(std::remove(str.begin(), str.end(), *it), str.end());
}
}  // namespace IDEA_internal

const char* IDEA_Init(const char* modeldir, const char* errlev) {
  using namespace IDEA;
  using namespace IDEA_internal;

  std::unordered_map<std::string, std::string> accuracy_info;
  {
    std::string temp = std::string(errlev);
    RemoveString(temp, std::vector<char>{' ', '\0', '\n', '\r', '\t'});
    std::vector<std::string> values = SplitString(temp, ',');
    for (auto&& v : values) {
      std::vector<std::string> pair = SplitString(v, '=');
      if (pair.size() == 2) {
        accuracy_info[pair[0]] = pair[1];
      }
    }
  }

  const std::string header = std::string(modeldir);
  string_buffer = "IDEA ver." + std::to_string(IDEA_VER_MAJOR) + "." +
                  std::to_string(IDEA_VER_MINOR) + "." +
                  std::to_string(IDEA_VER_SUBMINOR) + "\n";

  IDEA_MODEL_INIT(DEP);
  IDEA_MODEL_INIT(DET);
  IDEA_MODEL_INIT(DEH);
  IDEA_MODEL_INIT(DES);
  IDEA_MODEL_INIT(DEA);
  IDEA_MODEL_INIT(DEC);
  IDEA_MODEL_INIT(DEG);
  IDEA_MODEL_INIT(DEV);
  IDEA_MODEL_INIT(DEK);

  IDEA_MODEL_INIT(PTD);
  IDEA_MODEL_INIT(PTE);
  IDEA_MODEL_INIT(PTH);
  IDEA_MODEL_INIT(PTS);
  IDEA_MODEL_INIT(PTA);
  IDEA_MODEL_INIT(PTC);
  IDEA_MODEL_INIT(PTG);
  IDEA_MODEL_INIT(PTV);
  IDEA_MODEL_INIT(PTK);

  IDEA_MODEL_INIT(DPT);
  IDEA_MODEL_INIT(DPE);

  return string_buffer.c_str();
}
const char* IDEA_Finalize(void) {
  using namespace IDEA;

  string_buffer = "ANN model finialize!\n";

  DEP.reset();
  DET.reset();
  DEH.reset();
  DES.reset();
  DEA.reset();
  DEC.reset();
  DEG.reset();
  DEV.reset();
  DEK.reset();

  PTD.reset();
  PTE.reset();
  PTH.reset();
  PTS.reset();
  PTA.reset();
  PTC.reset();
  PTG.reset();
  PTV.reset();
  PTK.reset();

  DPT.reset();
  DPE.reset();

  return string_buffer.c_str();
}

const char* IDEA_Units(void) {
  using namespace IDEA;

  string_buffer =
      "Units used by IDEA\n"
      "D: density [kg/m3]\n"
      "P: pressure [Pa]\n"
      "T: temperature [K]\n"
      "E: specific energy [m2/s2]\n"
      "H: specific enthalpy [m2/s2]\n"
      "S: specific entropy [m2/s2/K]\n"
      "A: speed of sound [m/s]\n"
      "C: specific heat capacity at constant pressure [m2/s2/K]\n"
      "G: specific heat ratio\n"
      "V: viscosity [Pa*s]\n"
      "K: conductivity [W/m/K]\n";

  return string_buffer.c_str();
}

namespace IDEA {
std::string string_buffer;
}  // namespace IDEA

#define IDEA_MODEL_DEF(x1, x2, y)                                             \
  namespace IDEA {                                                            \
  std::shared_ptr<Model> x1##x2##y;                                           \
  }                                                                           \
  double IDEA_##x1##x2##y(const double x1, const double x2) {                 \
    using namespace IDEA;                                                     \
    const double x[2] = {std::log(x1), std::log(x2)};                         \
    double ln##y;                                                             \
    x1##x2##y->Pred(x, &ln##y);                                               \
    return std::exp(ln##y);                                                   \
  }                                                                           \
  double IDEA_##x1##x2##y##_Grad(double* grad, const double x1,               \
                                 const double x2) {                           \
    using namespace IDEA;                                                     \
    const double x[2] = {std::log(x1), std::log(x2)};                         \
    double ln##y;                                                             \
    x1##x2##y->Derivative(x, &ln##y, grad);                                   \
    const double y = std::exp(ln##y);                                         \
    grad[0] *= (y / x1);                                                      \
    grad[1] *= (y / x2);                                                      \
    return y;                                                                 \
  }                                                                           \
  double IDEA_##x1##x2##y##_Hess(double* hess, double* grad, const double x1, \
                                 const double x2) {                           \
    using namespace IDEA;                                                     \
    const double x[2] = {std::log(x1), std::log(x2)};                         \
    double ln##y;                                                             \
    x1##x2##y->Derivative2(x, &ln##y, grad, hess);                            \
    const double y = std::exp(ln##y);                                         \
    hess[0] = (y / x1 / x1) * (grad[0] * (grad[0] - 1.0) + hess[0]);          \
    hess[1] = (y / x1 / x2) * (grad[0] * grad[1] + hess[1]);                  \
    hess[2] = (y / x2 / x2) * (grad[1] * (grad[1] - 1.0) + hess[2]);          \
    grad[0] *= (y / x1);                                                      \
    grad[1] *= (y / x2);                                                      \
    return y;                                                                 \
  }

IDEA_MODEL_DEF(D, E, P);
IDEA_MODEL_DEF(D, E, T);
IDEA_MODEL_DEF(D, E, H);
IDEA_MODEL_DEF(D, E, S);
IDEA_MODEL_DEF(D, E, A);
IDEA_MODEL_DEF(D, E, C);
IDEA_MODEL_DEF(D, E, V);
IDEA_MODEL_DEF(D, E, K);

IDEA_MODEL_DEF(P, T, D);
IDEA_MODEL_DEF(P, T, E);
IDEA_MODEL_DEF(P, T, H);
IDEA_MODEL_DEF(P, T, S);
IDEA_MODEL_DEF(P, T, A);
IDEA_MODEL_DEF(P, T, C);
IDEA_MODEL_DEF(P, T, V);
IDEA_MODEL_DEF(P, T, K);

IDEA_MODEL_DEF(D, P, T);
IDEA_MODEL_DEF(D, P, E);

#define IDEA_MODEL_DEF2(x1, x2, y)                                            \
  namespace IDEA {                                                            \
  std::shared_ptr<Model> x1##x2##y;                                           \
  }                                                                           \
  double IDEA_##x1##x2##y(const double x1, const double x2) {                 \
    using namespace IDEA;                                                     \
    const double x[2] = {std::log(x1), std::log(x2)};                         \
    double y;                                                                 \
    x1##x2##y->Pred(x, &y);                                                   \
    return y;                                                                 \
  }                                                                           \
  double IDEA_##x1##x2##y##_Grad(double* grad, const double x1,               \
                                 const double x2) {                           \
    using namespace IDEA;                                                     \
    const double x[2] = {std::log(x1), std::log(x2)};                         \
    double y;                                                                 \
    x1##x2##y->Derivative(x, &y, grad);                                       \
    grad[0] /= x1;                                                            \
    grad[1] /= x2;                                                            \
    return y;                                                                 \
  }                                                                           \
  double IDEA_##x1##x2##y##_Hess(double* hess, double* grad, const double x1, \
                                 const double x2) {                           \
    using namespace IDEA;                                                     \
    const double x[2] = {std::log(x1), std::log(x2)};                         \
    double y;                                                                 \
    x1##x2##y->Derivative2(x, &y, grad, hess);                                \
    hess[0] = (hess[0] - grad[0]) / x1 / x1;                                  \
    hess[1] /= (x1 * x2);                                                     \
    hess[2] = (hess[2] - grad[1]) / x2 / x2;                                  \
    grad[0] /= x1;                                                            \
    grad[1] /= x2;                                                            \
    return y;                                                                 \
  }

IDEA_MODEL_DEF2(D, E, G);
IDEA_MODEL_DEF2(P, T, G);