#ifndef DATASET_H_
#define DATASET_H_

#include <vector>

#include "common.h"

namespace simpleml {
  template <class I, class L>
  class LabeledData {
   public:
    LabeledData(I input, L label) : input_(input), label_(label) {
    }

    LabeledData(const LabeledData<I, L> &data) {
      input_ = data.input_;
      label_ = data.label_;
    }

    I input() const {
      return input_;
    }

    L label() const {
      return label_;
    }

   private:
    I input_;
    L label_;
  };

  template <class T>
  class Dataset {
   public:
    Dataset(const std::vector<T> &dataset) : elements_(dataset) {
      size_ = elements_.size();
    }

    Dataset(const Dataset<T> &dataset) {
      elements_ = dataset.elements_;
      size_ = dataset.size_;
    }

    std::vector<T> elements() const {
      return elements_;
    }

    unsigned size() const {
      return size_;
    }

    bool empty() const {
      return size_ == 0;
    }

   protected:
    std::vector<T> elements_;
    unsigned size_;
  };

  template <class I, class L>
  class LabeledDataset : public Dataset<LabeledData<I, L> > {
   public:
    LabeledDataset(const std::vector<LabeledData<I, L> > &dataset) 
      : Dataset<LabeledData<I, L> >(dataset) {
      typedef typename std::vector<LabeledData<I, L> >::const_iterator iterator;
      for (iterator iter = dataset.begin(); iter != dataset.end(); ++iter) {
        inputs_.push_back(iter->input());
        labels_.push_back(iter->label());
      }
    }

    LabeledDataset(const LabeledDataset<I, L> &dataset) {
      this->elements_ = dataset.elements_;
      inputs_ = dataset.inputs_;
      labels_ = dataset.labels_;
    }

    std::vector<I> inputs() const {
      return inputs_;
    }

    std::vector<L> labels() const {
      return labels_;
    }

   private:
    std::vector<I> inputs_;
    std::vector<L> labels_;
  };
}

#endif  // DATASET_H_
