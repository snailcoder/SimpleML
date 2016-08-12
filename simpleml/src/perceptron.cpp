#include <algorithm>

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

  void Perceptron::original(const ClassificationDataset &data, unsigned max_iter) {
    if (!data.empty()) {
      unsigned err_count = 0;
      unsigned size = data.size();
      // typedef ClassificationDataset::const_iterator iterator;
      std::vector<ClassificationData> elements = data.elements();
      typedef std::vector<ClassificationData>::iterator iterator;
      for (unsigned i = 0; i < max_iter; ++i) {
        for (iterator iter = elements.begin(); iter != elements.end(); ++iter) {
          double product = (dot_product<double>(weight_, iter->input()) + bias_) * iter->label();
          if (product <= 0) {
            ++err_count;
            weight_ += learning_rate_ * iter->label() * iter->input();
            bias_ += learning_rate_ * static_cast<double>(iter->label());
          }
        }
        if (err_count == 0) break;
      }
    }
  }

  void Perceptron::dual(const ClassificationDataset &data, unsigned max_iter) {
    if (!data.empty()) {
      unsigned err_count = 0;
      unsigned size = data.size();
      RealVector alpha(size, 0.0);
      std::vector<ClassificationData> elements = data.elements();
      typedef std::vector<ClassificationData>::iterator iterator;
      std::vector<RealVector> inputs = data.inputs();
      std::vector<int> labels = data.labels();
      std::vector<std::vector<double> > gram = gram_matrix(inputs);
      for (unsigned i = 0; i < max_iter; ++i) {
        for (iterator iter = elements.begin(); iter != elements.end(); ++iter) {
          double product_sum = 0.0;
          unsigned k = iter - elements.begin();
          for (unsigned j = 0; j < size; ++j) {
            product_sum += alpha[j] * labels[j] * gram[j][k];
          }
          if ((product_sum + bias_) * labels[k] <= 0) {
            ++err_count;
            alpha[k] += learning_rate_;
            bias_ += learning_rate_ * static_cast<double>(iter->label());
          }
        }
        if (err_count == 0) break;
      }
      for (unsigned l = 0; l < size; ++l) {
        weight_ += alpha[l] * labels[l] * inputs[l];
      }
    }
  }

  void Perceptron::train(const ClassificationDataset &data, unsigned max_iter, int form) {
    switch (form) {
      case 1:
        dual(data, max_iter);
        break;
      default:
        original(data, max_iter);
    }
  }

  int Perceptron::predict(const RealVector &data) const {
    return sign(dot_product(weight_, data) + bias_);
  }
}
