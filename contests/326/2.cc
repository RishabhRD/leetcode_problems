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
  int distinctPrimeFactors(std::vector<int>& nums) {
    auto const max = *std::max_element(std::begin(nums), std::end(nums));
    std::vector<std::vector<ll>> prime_factors(max + 1);
    for (ll i = 2; i <= max; ++i) {
      if (prime_factors[i].size() == 0) {
        for (ll j = i; j <= max; j += i) {
          prime_factors[j].push_back(i);
        }
      }
    }
    std::unordered_set<ll> st;
    for (auto n : nums) {
      for (auto x : prime_factors[n]) st.insert(x);
    }
    return st.size();
  }
};
