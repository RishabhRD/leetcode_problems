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
  int countSubarrays(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    auto const idx =
        std::find(std::begin(nums), std::end(nums), k) - std::begin(nums);
    std::unordered_map<int, int> mp;
    int ans = 0;
    {
      int balance = 0;
      for (int i = idx; i < n; ++i) {
        if (nums[i] > k) ++balance;
        if (nums[i] < k) --balance;
        ++mp[balance];
      }
    }
    {
      int balance = 0;
      for (int i = idx; i >= 0; --i) {
        if (nums[i] > k) ++balance;
        if (nums[i] < k) --balance;
        ans += mp[-balance];
        ans += mp[-(balance - 1)];
      }
    }
    return ans;
  }
};
