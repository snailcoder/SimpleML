#include "perceptron.h"
#include "math.h"

#include <iostream>

namespace simpleml {
  Perceptron::Perceptron(const RealVector &weight, double bias, double learning_rate)
    : weight_(weight), bias_(bias), learning_rate_(learning_rate) {
    }
  
  double Perceptron::learning_rate() const {
    return learning_rate_;
  }

  void Perceptron::set_learning_rate(double learning_rate) {
    learning_rate_ = learning_rate;
  }

  RealVector Perceptron::weight() const {
    return weight_;
  }

  void Perceptron::set_weight(const RealVector &weight) {
    weight_ = weight;
  }

  double Perceptron::bias() const {
    return bias_;
  }

  void Perceptron::set_bias(double bias) {
    bias_ = bias;
  }

  void Perceptron::train(const ClassificationDataset &data, unsigned max_iter) {
    if (!data.empty()) {
      unsigned err_count = 0;
      unsigned size = data.size();
      typedef ClassificationDataset::const_iterator iterator;
      for (unsigned i = 0; i < max_iter; ++i) {
        for (iterator iter = data.begin(); iter != data.end(); ++iter) {
          double product = (dot_product<double>(weight_, iter->first) + bias_) * iter->second;
          if (product <= 0) {
            ++err_count;
            weight_ += learning_rate_ * iter->second * iter->first;
            bias_ += learning_rate_ * static_cast<double>(iter->second);
          }
        }
        if (err_count == 0) break;
      }
    }
  }

  int Perceptron::predict(const RealVector &data) const {
    return sign(dot_product(weight_, data) + bias_);
  }
}
