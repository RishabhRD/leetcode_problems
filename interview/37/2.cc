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
  vector<vector<int>> intervalIntersection(vector<vector<int>> &a,
    vector<vector<int>> &b) {
    auto end = [](const auto &x) { return x[1]; };
    auto start = [](const auto &x) { return x[0]; };
    vector<vector<int>> res;
    for (int i = 0, j = 0; i < size(a) and j < size(b);) {
      if (end(a[i]) < start(b[j])) {
        i++;
      } else if (end(b[j]) < start(a[i])) {
        j++;
      } else {
        res.push_back(
          { max(start(a[i]), start(b[j])), min(end(a[i]), end(b[j])) });
        if (end(a[i]) < end(b[j]))
          i++;
        else
          j++;
      }
    }
    return res;
  }
};
