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
  long long countGood(std::vector<int>& nums, int k) {
    ll const n = nums.size();
    ll low = 0;
    std::unordered_map<ll, ll> cnt;
    ll cur = 0;
    ll sum = 0;
    for (ll high = 0; high < n; ++high) {
      cur -= (cnt[nums[high]] * (cnt[nums[high]] - 1)) / 2;
      ++cnt[nums[high]];
      cur += (cnt[nums[high]] * (cnt[nums[high]] - 1)) / 2;
      while (cur >= k) {
        cur -= (cnt[nums[low]] * (cnt[nums[low]] - 1)) / 2;
        --cnt[nums[low]];
        cur += (cnt[nums[low]] * (cnt[nums[low]] - 1)) / 2;
        ++low;
      }
      sum += (high - low + 1);
    }
    return (n * (n + 1)) / 2 - sum;
  }
};
