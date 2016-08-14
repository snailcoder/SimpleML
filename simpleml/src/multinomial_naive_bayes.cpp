#include "multinomial_naive_bayes.h"

namespace simpleml {
  typedef MultinomialNaiveBayes::ClassMap CLassMap;
  typedef MultinomialNaiveBayes::FeatureMap FeatureMap;

  MultinomialNaiveBayes::MultinomialNaiveBayes(const std::vector<std::vector<int> > &inputs, 
                                               const std::vector<int> &labels, 
                                               double lambda) 
    : features_(features), classes_(classes), lambda_(lambda) {
  }

  void MultinomialNaiveBayes::train(const LabeledDataset<int, int> &data) {
    if (!data.empty()) {
      unsigned size = data.size();
      std::vector<std::vector<int> > inputs = data.inputs();
      std::vector<int> labels = data.labels();
      std::unordered_map<int, unsigned> features;
      typedef std::vector<std::vector<int> >::iterator i_iterator;
      typedef std::vector<int>::iterator f_iterator;
      for (std::vector<int>::iterator c_iter = classes_.begin(); 
          c_iter != classes_.end(); ++c_iter) {
        
      }
      for (i_iterator i_iter = inputs.begin(); i_iter != inputs.end(); ++i_iter) {
        for(f_iterator f_iter = i_iter->begin(); f_iter != i_iter->end(); ++f_iter) {
          ++features[*f_iter];
        }
      }
    }
  }

  int MultinomialNaiveBayes::predict(const LabeledData &data) {
  }

  FeatureMap MultinomialNaiveBayes::count_features(
      const LabeledDataset<int, int> &data) {
    FeatureMap features;
    std::vector<LabeledData<int, int> > elements = data.elements();
    typedef std::vector<LabeledData<int, int> >::iterator iterator;
    for (std::vector<int>::iterator c_iter = classes_.begin(); 
        c_iter != classes_.end(); ++c_iter) {
      for (iterator e_iter = elements.begin(); 
          e_iter != elements.end(); ++e_iter) {
        std::vector<int> input = e_iter->input();
        for (std::vector<int>::iterator f_iter = input.begin(); 
            f_iter != input.end(); ++f_iter) {
          make_pair()
        }
      }
    }
    for (iterator e_iter = elements.begin(); e_iter != elements.end(); ++e_iter) {
      if (e_iter->label() == c) {
        std::vector<int> input = e_iter->input();
        for (std::vector<int>::iterator iter = input.begin(); 
            iter != input.end(); ++iter) {
          ++features[*iter];
        }
      }
    }
    return features;
  }

  ClassMap MultinomialNaiveBayes::count_classes(
      const LabeledData<int, unsigned> &data) {
    ClassMap classes;
    std::vector<int> labels = data.labels();
    for (std::vector<int>::iterator l_iter = labels.begin(); 
        l_iter != labels.end(); ++l_iter) {
      ++classes[*c_iter];
    }
    return classes;
  }
}
