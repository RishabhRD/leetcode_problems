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
  int minNumberOperations(std::vector<int>& target) {
    int ans = target[0];
    for (int i = 1; i < std::size(target); ++i) {
      ans += std::max(target[i] - target[i - 1], 0);
    }
    return ans;
  }
};
