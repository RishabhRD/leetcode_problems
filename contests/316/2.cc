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
  int subarrayGCD(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ll gcd = nums[i];
      for (int j = i; j < n; ++j) {
        gcd = std::gcd<ll>(gcd, nums[j]);
        if (gcd == k) ++ans;
      }
    }
    return ans;
  }
};
