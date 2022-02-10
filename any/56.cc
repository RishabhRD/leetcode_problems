#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(begin(intervals), end(intervals), [](auto const &i1, auto const &i2) {
      return i1[0] < i2[0];
    });
    vector<vector<int>> res;
    res.push_back(intervals.front());
    for (int i = 1; i < size(intervals); i++) {
      auto const &cur_interval = intervals[i];
      auto &filled_interval = res.back();
      if (cur_interval[0] <= filled_interval[1]) {
        filled_interval[1] = max(cur_interval[1], filled_interval[1]);
      } else {
        res.push_back(cur_interval);
      }
    }
    return res;
  }
};
