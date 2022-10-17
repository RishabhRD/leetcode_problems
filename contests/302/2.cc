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

int sum_digit(int num) {
  int sum = 0;
  while (num) {
    sum += (num % 10);
    num = num / 10;
  }
  return sum;
}

class Solution {
 public:
  int maximumSum(std::vector<int>& nums) {
    std::unordered_map<int, std::multiset<int, std::greater<int>>> mp;
    for (auto ele : nums) {
      mp[sum_digit(ele)].insert(ele);
    }
    int ans = -1;
    for (auto const& [k, v] : mp) {
      if (v.size() >= 2) {
        auto itr = v.begin();
        auto const first = *itr;
        ++itr;
        auto const second = *itr;
        ans = std::max(ans, first + second);
      }
    }
    return ans;
  }
};
