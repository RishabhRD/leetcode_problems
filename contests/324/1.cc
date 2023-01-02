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
  int similarPairs(std::vector<std::string>& words) {
    std::unordered_map<ll, ll> nums;
    for (std::string_view word : words) {
      std::bitset<26> bs;
      for (auto c : word) {
        bs[c - 'a'] = true;
      }
      ++nums[bs.to_ullong()];
    }
    ll sum = 0;
    for (auto [k, v] : nums) {
      sum += (v * (v - 1)) / 2;
    }
    return sum;
  }
};
