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

class Solution {
 public:
  long long minimumMoney(std::vector<std::vector<int>>& transactions) {
    long long total_loss = 0;
    for (auto const& vec : transactions) {
      if (vec[0] - vec[1] >= 0) total_loss += vec[0] - vec[1];
    }
    long long max_ans = INT64_MIN;
    for (auto const& vec : transactions) {
      auto loss = total_loss;
      loss -= (vec[0] - vec[1]);
      loss += vec[0];
      max_ans = std::max(max_ans, loss);
    }
    return max_ans;
  }
};
