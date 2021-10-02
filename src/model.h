#pragma once

#include <memory>
#include <string>
#include <vector>

namespace IDEA {
class Model {
 private:
  const int& m;  // reserved for num_hidden_

  int num_hidden_;               // m
  int num_parameter_;            // 4*m+1
  std::vector<double> weights_;  // (VECTOR) 4*m+1

  bool x1_log_;
  bool x2_log_;
  bool y_log_;
  double accuracy_;

  double* Ao_;  // (VECTOR) 1 * m
  double* bo_;  // (SCALAR) 1 * 1
  double* Ai_;  // (MATRIX) m * 2
  double* bi_;  // (VECTOR) m * 1
  
  std::vector<double> yi_;  // (VECTOR) m * 1

  // f = Ao*xo + bo
  // xo = Transfer(yi)
  // yi =  Ai*x + bi

 public:
  Model();
  ~Model(){};

  inline double GetAccuracy(void) const { return accuracy_; };

  bool Init(const std::string& filename);
  void Pred(const double* x, double* f);
  void Derivative(const double* x, double* dfdx);
  void Derivative(const double* x, double* f, double* dfdx);

 private:
  inline double Transfer(const double input) const;
  inline double DiffTransfer(const double input) const;
};

extern std::string string_buffer;

extern std::shared_ptr<Model> DEP;
extern std::shared_ptr<Model> DET;
extern std::shared_ptr<Model> DEH;
extern std::shared_ptr<Model> DES;
extern std::shared_ptr<Model> DEA;
extern std::shared_ptr<Model> DEC;
extern std::shared_ptr<Model> DEG;
extern std::shared_ptr<Model> DEV;
extern std::shared_ptr<Model> DEK;

extern std::shared_ptr<Model> PTD;
extern std::shared_ptr<Model> PTE;
extern std::shared_ptr<Model> PTH;
extern std::shared_ptr<Model> PTS;
extern std::shared_ptr<Model> PTA;
extern std::shared_ptr<Model> PTC;
extern std::shared_ptr<Model> PTG;
extern std::shared_ptr<Model> PTV;
extern std::shared_ptr<Model> PTK;

extern std::shared_ptr<Model> DPT;
extern std::shared_ptr<Model> DPE;
}  // namespace IDEA