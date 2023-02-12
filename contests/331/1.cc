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
  long long pickGifts(std::vector<int>& gifts, int k) {
    std::priority_queue<ll> pq{std::begin(gifts), std::end(gifts)};
    for (ll i = 0; i < k; ++i) {
      auto const top = pq.top();
      pq.pop();
      pq.push(std::sqrt(top));
    }
    ll sum = 0;
    while (not std::empty(pq)) {
      sum += pq.top();
      pq.pop();
    }
    return sum;
  }
};
