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

class Solution {
 public:
  int numOfSubarrays(std::vector<int>& arr) {
    constexpr static int mod = 1e9 + 7;
    auto const n = std::size(arr);
    std::vector even(n, 0);
    std::vector odd(n, 0);
    if (arr[0] % 2 == 0)
      even[0] = 1;
    else
      odd[0] = 1;
    for (int i = 1; i < n; ++i) {
      auto const num = arr[i];
      if (num % 2 == 0) {
        even[i] = (even[i - 1] + 1) % mod;
        odd[i] = odd[i - 1];
      } else {
        even[i] = odd[i - 1];
        odd[i] = (even[i - 1] + 1) % mod;
      }
    }
    return std::accumulate(
        std::begin(odd), std::end(odd), 0,
        [](auto a, auto b) { return (a % mod + b % mod) % mod; });
  }
};
