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

class Solution {
 public:
  int averageValue(std::vector<int>& nums) {
    int sum = 0;
    int cnt = 0;
    for (auto e : nums) {
      if (e % 2 == 0 and e % 3 == 0) {
        sum += e;
        ++cnt;
      }
    }
    if (cnt == 0) return 0;
    return sum / cnt;
  }
};
