#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int const n = size(intervals);
    sort(begin(intervals), end(intervals),
         [](auto& vec1, auto& vec2) { return vec1.back() < vec2.back(); });
    int end = intervals[0].back();
    int count = 1;
    for (int i = 1; i < n; ++i) {
      if (intervals[i].front() >= end) {
        end = intervals[i].back();
        ++count;
      }
    }
    return n - count;
  }
};
