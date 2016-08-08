#ifndef MATH_H_
#define MATH_H_

#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iostream>

#include "common.h"

namespace simpleml {
  template<class T>
  int sign(const T &t) {
    return t >= 0 ? 1 : -1;
  }

  template<class T>
  T dot_product(const std::vector<T> &v1, const std::vector<T> &v2) {
    assert(v1.size() == v2.size());

    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
  }

  template<class T>
  std::vector<T> operator*(const T &m, const std::vector<T> &v) {
    std::vector<T> result;
    result.reserve(v.size());
    std::transform(v.begin(), v.end(), std::back_inserter(result), 
		   std::bind1st(std::multiplies<T>(), m));
    return result;
  }

  template<class T>
  std::vector<T> operator*(const std::vector<T> &v, const T &m) {
    std::vector<T> result;
    result.reserve(v.size());
    std::transform(v.begin(), v.end(), std::back_inserter(result), 
		   std::bind1st(std::multiplies<T>(), m));
    return result;
  }

  template<class T>
  std::vector<T>& operator*=(std::vector<T> &v, const T &m) {
    std::transform(v.begin(), v.end(), v.begin(), 
                   std::bind1st(std::multiplies<T>(), m));
    return v;
  }

  template<class T>
  std::vector<T> operator+(const std::vector<T> &v1, const std::vector<T> &v2) {
    assert(v1.size() == v2.size());
    
    std::vector<T> result;
    result.reserve(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), 
                   std::back_inserter(result), std::plus<T>());
    return result;
  }

  template<class T>
  std::vector<T>& operator+=(std::vector<T> &v1, const std::vector<T> &v2) {
    assert(v1.size() == v2.size());

    std::transform(v1.begin(), v1.end(), v2.begin(), 
		   v1.begin(), std::plus<T>());
    return v1;
  }
}

#endif  // MATH_H_
