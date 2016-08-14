#ifndef MULTINOMIAL_NAIVE_BAYES_H_
#define MULTINOMIAL_NAIVE_BAYES_H_

#include <vector>
#include <unordered_map>
#include <utility>

#include "common.h"

namespace simpleml {
  class MultinomialNaiveBayes {
   public:
    MultinomialNaiveBayes(const std::vector<std::vector<int> > &features,                          const std::vector<int> &classes, 
                          double lambda = 0.0);
    void train(const LabeledDataset<int, int> &data);
    int predict(const LabeledData &data);
   private:
    typedef unordered_map<std::pair<int, int>, unsigned> FeatureMap;
    typedef unordered_map<int, unsigned> ClassMap;
    ClassMap count_classes(const LabeledDataset<int, int> &data);
    FeatureMap count_features(const LabeledDataset<int, int> &elements);
    
    std::vector<std::vector<int> > features_;
    std::vector<int> classes_;
    std::unordered_map<int, double> prior_prob_;
    std::unordered_map<std::pair<int, int>, double> conditional_prob_;
    double lambda_;
  };
}

#endif  // MULTINOMIAL_NAIVE_BAYES_H_
