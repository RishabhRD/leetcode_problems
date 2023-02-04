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
  long long putMarbles(std::vector<int> &weights, int k) {
    auto const n = weights.size();
    std::vector<ll> candidates;
    for (ll i = 0; i < n - 1; ++i) {
      candidates.push_back(weights[i] + weights[i + 1]);
    }
    std::sort(std::begin(candidates), std::end(candidates));
    ll mins = 0;
    ll maxs = 0;
    for (ll i = 0; i < k - 1; ++i) {
      mins += candidates[i];
      maxs += candidates[candidates.size() - i - 1];
    }
    return maxs - mins;
  }
};
