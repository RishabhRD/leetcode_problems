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
  int countDistinct(std::vector<int>& nums, int k, int p) {
    auto const n = nums.size();
    ll low = 0;
    ll total = 0;
    ll cur_cnt = 0;
    std::set<std::vector<ll>> st;
    for (ll high = 0; high < n; ++high) {
      cur_cnt += nums[high] % p == 0;
      while (cur_cnt > k) {
        cur_cnt -= nums[low] % p == 0;
        ++low;
      }
      std::vector<ll> res;
      for (ll i = high; i >= low; --i) {
        res.push_back(nums[i]);
        st.insert(res);
      }
    }
    return st.size();
  }
};
