#include <iostream>
#include <vector>

#include "perceptron.h"
#include "common.h"

using namespace std;
using namespace simpleml;

int main() {
  double w[] = {0, 0};
  RealVector weight(w, w + 2);
  Perceptron perceptron(weight);

  double x1[] = {3, 3};
  double x2[] = {4, 3};
  double x3[] = {1, 1};
  
  vector<ClassificationData> data;
  ClassificationData training_data1(RealVector(x1, x1 + 2), 1);
  ClassificationData training_data2(RealVector(x2, x2 + 2), 1);
  ClassificationData training_data3(RealVector(x3, x3 + 2), -1);

  data.push_back(training_data1);
  data.push_back(training_data2);
  data.push_back(training_data3);

  ClassificationDataset training_dataset(data);
  perceptron.train(training_dataset, 100);
  cout << perceptron.bias() << endl;
  RealVector perceptron_weight(perceptron.weight());
  for (RealVector::iterator iter = perceptron_weight.begin();
      iter != perceptron_weight.end(); ++iter) {
    cout << *iter << endl;
  }

  return 0;
}
