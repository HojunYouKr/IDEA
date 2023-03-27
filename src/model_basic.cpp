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
      bi_(nullptr) {}
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

  for (int i = 0; i < num_parameter_; i++) fin >> weights_[i];
  fin.close();
  return true;
}
void Model::Pred(const double* x, double* f) const {
  *f = bo_[0];
  for (int i = 0; i < m; i++) {
    const double yi = Ai_[i * 2] * x[0] + Ai_[i * 2 + 1] * x[1] + bi_[i];
    *f += (Ao_[i] * Transfer(yi));
  }
}
void Model::Pred(const int n, const double* x, double* f) const {
  for (int j = 0; j < n; j++) {
    f[j] = bo_[0];
    const double x1 = x[2 * j];
    const double x2 = x[2 * j + 1];
    for (int i = 0; i < m; i++) {
      const double yi = Ai_[i * 2] * x1 + Ai_[i * 2 + 1] * x2 + bi_[i];
      f[j] += (Ao_[i] * Transfer(yi));
    }
  }
}
void Model::Derivative(const double* x, double* dfdx) const {
  dfdx[0] = dfdx[1] = 0.0;
  for (int i = 0; i < m; i++) {
    const double temp =
        DiffTransfer(Ai_[i * 2] * x[0] + Ai_[i * 2 + 1] * x[1] + bi_[i]) *
        Ao_[i];
    dfdx[0] += (temp * Ai_[i * 2]);
    dfdx[1] += (temp * Ai_[i * 2 + 1]);
  }
}
void Model::Derivative(const double* x, double* f, double* dfdx) const {
  *f = bo_[0];
  dfdx[0] = dfdx[1] = 0.0;
  for (int i = 0; i < m; i++) {
    const double yi = Ai_[i * 2] * x[0] + Ai_[i * 2 + 1] * x[1] + bi_[i];
    *f += (Ao_[i] * Transfer(yi));

    const double temp = DiffTransfer(yi) * Ao_[i];
    dfdx[0] += (temp * Ai_[i * 2]);
    dfdx[1] += (temp * Ai_[i * 2 + 1]);
  }
}
void Model::Derivative2(const double* x, double* f, double* dfdx,
                        double* dfdx2) const {
  *f = bo_[0];
  dfdx[0] = dfdx[1] = 0.0;
  dfdx2[0] = dfdx2[1] = dfdx2[2] = 0.0;
  for (int i = 0; i < m; i++) {
    const double yi = Ai_[i * 2] * x[0] + Ai_[i * 2 + 1] * x[1] + bi_[i];
    *f += (Ao_[i] * Transfer(yi));

    const double temp = DiffTransfer(yi) * Ao_[i];
    dfdx[0] += (temp * Ai_[i * 2]);
    dfdx[1] += (temp * Ai_[i * 2 + 1]);

    const double temp2 = Diff2Transfer(yi) * Ao_[i];
    dfdx2[0] += (temp2 * Ai_[i * 2] * Ai_[i * 2]);
    dfdx2[1] += (temp2 * Ai_[i * 2] * Ai_[i * 2 + 1]);
    dfdx2[2] += (temp2 * Ai_[i * 2 + 1] * Ai_[i * 2 + 1]);
  }
}
inline double Model::Transfer(const double input) const {
  return 1.0 / (1.0 + std::exp(input));
}
inline double Model::DiffTransfer(const double input) const {
  const double s = Transfer(input);
  return s * (s - 1.0);
}
inline double Model::Diff2Transfer(const double input) const {
  const double s = Transfer(input);
  return s * (s - 1.0) * (2.0 * s - 1.0);
}
}  // namespace IDEA
