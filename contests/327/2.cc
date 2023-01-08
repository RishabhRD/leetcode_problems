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
  long long maxKelements(std::vector<int>& nums, int k) {
    std::priority_queue<ll> pq{std::begin(nums), std::end(nums)};
    ll sum = 0;
    for (ll i = 0; i < k; ++i) {
      auto const cur = pq.top();
      sum += cur;
      pq.pop();
      pq.push(std::ceil(cur / 3.0));
    }
    return sum;
  }
};
