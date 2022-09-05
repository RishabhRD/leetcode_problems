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
  int maxSumDivThree(std::vector<int>& nums) {
    auto rem1 = 20000, rem2 = 20000;
    auto sum = 0;
    for (auto const num : nums) {
      sum += num;
      if (num % 3 == 1) {
        rem2 = std::min(rem2, rem1 + num);
        rem1 = std::min(rem1, num);
      } else if (num % 3 == 2) {
        rem1 = std::min(rem1, rem2 + num);
        rem2 = std::min(rem2, num);
      }
    }
    if (sum % 3 == 0)
      return sum;
    else if (sum % 3 == 1)
      return sum - rem1;
    else
      return sum - rem2;
  }
};
