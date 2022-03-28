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
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (empty(left))
      left.push(num);
    else {
      if (num <= left.top()) {
        left.push(num);
        if (size(left) - size(right) >= 2) {
          auto const left_top = left.top();
          left.pop();
          right.push(left_top);
        }
      } else {
        right.push(num);
        if (size(right) > size(left)) {
          auto const right_top = right.top();
          right.pop();
          left.push(right_top);
        }
      }
    }
  }

  double findMedian() {
    if (size(left) != size(right)) {
      return left.top();
    } else {
      return (left.top() + right.top()) / 2.0;
    }
  }
};
