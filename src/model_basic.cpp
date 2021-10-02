#include "model.h"

#include <cmath>
#include <fstream>

namespace IDEA {
Model::Model()
    : m(num_hidden_),
      num_hidden_(0),
      num_parameter_(0),
      weights_(),
      x1_log_(true),
      x2_log_(true),
      y_log_(true),
      accuracy_(0.0),
      Ao_(nullptr),
      bo_(nullptr),
      Ai_(nullptr),
      bi_(nullptr),
      yi_() {}
bool Model::Init(const std::string& filename) {
  std::ifstream fin(filename);
  if (fin.is_open() == false) return false;

  fin >> num_hidden_ >> num_parameter_;
  fin >> x1_log_ >> x2_log_ >> y_log_;
  fin >> accuracy_;

  weights_.resize(num_parameter_);
  Ao_ = &weights_[0];
  bo_ = &weights_[m];
  Ai_ = &weights_[m + 1];
  bi_ = &weights_[3 * m + 1];
  yi_.resize(m, 0.0);

  for (int i = 0; i < num_parameter_; i++) fin >> weights_[i];
  fin.close();
  return true;
}
void Model::Pred(const double* x, double* f) {
  *f = bo_[0];
  for (int i = 0; i < m; i++) {
    yi_[i] = Ai_[i * 2] * x[0] + Ai_[i * 2 + 1] * x[1] + bi_[i];
    *f += (Ao_[i] * Transfer(yi_[i]));
  }
}
void Model::Derivative(const double* x, double* dfdx) {
  dfdx[0] = dfdx[1] = 0.0;
  for (int i = 0; i < m; i++) {
    const double temp =
        DiffTransfer(Ai_[i * 2] * x[0] + Ai_[i * 2 + 1] * x[1] + bi_[i]) *
        Ao_[i];
    dfdx[0] += (temp * Ai_[i * 2]);
    dfdx[1] += (temp * Ai_[i * 2] + 1);
  }
}
void Model::Derivative(const double* x, double* f, double* dfdx) {
  Pred(x, f);
  dfdx[0] = dfdx[1] = 0.0;
  for (int i = 0; i < m; i++) {
    const double temp = DiffTransfer(yi_[i]) * Ao_[i];
    dfdx[0] += (temp * Ai_[i * 2]);
    dfdx[1] += (temp * Ai_[i * 2] + 1);
  }
}
inline double Model::Transfer(const double input) const {
  return 1.0 / (1.0 + std::exp(input));
}
inline double Model::DiffTransfer(const double input) const {
  const double s = Transfer(input);
  return s * (s - 1.0);
}
}  // namespace IDEA