#ifndef COMMON_H_
#define COMMON_H_

#include <vector>
#include <utility>

#include "dataset.h"

namespace simpleml {
  typedef std::vector<double> RealVector;
  typedef LabeledData<RealVector, int> ClassificationData;
  typedef LabeledData<RealVector, double> RegressionData;
  typedef LabeledDataset<RealVector, int> ClassificationDataset;
  typedef LabeledDataset<RealVector, double> RegressionDataset;
  //typedef std::pair<RealVector, int> ClassificationData;
  //typedef std::pair<RealVector, double> RegressionData;
  //typedef std::vector<ClassificationData > ClassificationDataset;
  //typedef std::vector<RegressionData> RegressionDataset;
}

#endif  // COMMON_H_
