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

ll merge(ll low, ll mid, ll high, std::vector<ll>& nums) {
  ll j = mid + 1;
  ll cnt = 0;
  for (ll i = low; i <= mid; ++i) {
    while (j <= high && nums[i] - 2 * nums[j] <= 0) ++j;
    cnt += high - j + 1;
  }
  std::sort(std::begin(nums) + low, std::begin(nums) + high + 1,
            std::greater<>{});
  return cnt;
}

ll reverse_pairs(ll low, ll high, std::vector<ll>& nums) {
  if (high <= low) return 0;
  auto const mid = (low + high) / 2;
  auto const left = reverse_pairs(low, mid, nums);
  auto const right = reverse_pairs(mid + 1, high, nums);
  auto const middle = merge(low, mid, high, nums);
  return left + right + middle;
}

class Solution {
 public:
  int reversePairs(std::vector<int>& nums) {
    std::vector<ll> my_nums{std::begin(nums), std::end(nums)};
    return reverse_pairs(0, nums.size() - 1, my_nums);
  }
};
