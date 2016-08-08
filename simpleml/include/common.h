#ifndef COMMON_H_
#define COMMON_H_

#include <vector>
#include <utility>

namespace simpleml {
  typedef std::vector<double> RealVector;
  typedef std::pair<RealVector, int> ClassificationData;
  typedef std::pair<RealVector, double> RegressionData;
  typedef std::vector<ClassificationData > ClassificationDataset;
  typedef std::vector<RegressionData> RegressionDataset;
}

#endif  // COMMON_H_
