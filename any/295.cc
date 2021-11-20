#include <queue>
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class MedianFinder {
  priority_queue<double> f_h;
  priority_queue<double, vector<double>, greater<double>> s_h;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (size(f_h) == size(s_h)) {
      s_h.push(num);
      f_h.push(s_h.top());
      s_h.pop();
    } else {
      f_h.push(num);
      s_h.push(f_h.top());
      f_h.pop();
    }
  }

  double findMedian() {
    if (size(f_h) == size(s_h)) {
      return (f_h.top() + s_h.top()) / 2;
    } else {
      return f_h.top();
    }
  }
};
