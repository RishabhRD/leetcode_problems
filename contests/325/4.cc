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

constexpr ll mod = 1e9 + 7;

ll dfs(ll i, ll left_sum, ll right_sum, std::vector<int> const& nums,
       ll const k, std::vector<std::unordered_map<ll, ll>>& mp) {
  if (i >= std::size(nums)) return left_sum >= k and right_sum >= k;
  if (mp[i].find(left_sum) != mp[i].end()) return mp[i][left_sum];
  return mp[i][left_sum] =
             (dfs(i + 1, left_sum + nums[i], right_sum, nums, k, mp) +
              dfs(i + 1, left_sum, right_sum + nums[i], nums, k, mp)) %
             mod;
}

class Solution {
 public:
  int countPartitions(std::vector<int>& nums, int k) {
    auto const n = std::size(nums);
    std::vector<std::unordered_map<ll, ll>> mp(n);
    return dfs(0, 0, 0, nums, k, mp);
  }
};
