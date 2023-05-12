#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

class MedianFinder {
  std::priority_queue<ll> left;
  std::priority_queue<ll, std::vector<ll>, std::greater<ll>> right;

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (left.empty() || num <= left.top()) {
      left.push(num);
    } else {
      right.push(num);
    }
    ll const l = left.size();
    ll const r = right.size();
    if (l - r > 1) {
      auto const top = left.top();
      left.pop();
      right.push(top);
    } else if (r > l) {
      auto const top = right.top();
      right.pop();
      left.push(top);
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return (left.top() + right.top()) / 2.0;
    }
    return left.top();
  }
};
