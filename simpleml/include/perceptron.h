#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include "common.h"

namespace simpleml {
  class Perceptron {
   public:
    Perceptron(const RealVector &weight, double bias = 0.0, double learning_rate = 1.0);
    double learning_rate() const;
    void set_learning_rate(double learning_rate);
    RealVector weight() const;
    void set_weight(const RealVector &weight);
    double bias() const;
    void set_bias(double bias);
    void train(const ClassificationDataset &data, unsigned max_iterations);
    int predict(const RealVector &data) const;
   private:
    double learning_rate_;
    RealVector weight_;
    double bias_;
  };
}

#endif  // PERCEPTRON_H_
