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
  long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<std::pair<ll, ll>> nums;
    ll const n = std::size(nums1);
    for (ll i = 0; i < n; ++i) {
      nums.push_back({nums1[i], nums2[i]});
    }
    std::sort(std::begin(nums), std::end(nums),
              [](auto a, auto b) { return a.second < b.second; });
    std::vector<ll> suffix_sum(n);
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    ll cur_sum = 0;
    for (ll i = n - 1; i >= 0; --i) {
      cur_sum += nums[i].first;
      pq.push(nums[i].first);
      if (pq.size() > k) {
        auto const top = pq.top();
        pq.pop();
        cur_sum -= top;
      }
      suffix_sum[i] = cur_sum;
    }
    ll ans = 0;
    for (ll i = 0; i <= n - k; ++i) {
      ll const cur = nums[i].second * suffix_sum[i];
      ans = std::max(ans, cur);
    }
    return ans;
  }
};
