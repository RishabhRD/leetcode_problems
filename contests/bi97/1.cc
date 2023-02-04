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

auto get_digits(ll n) {
  std::vector<int> digits;
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  std::reverse(std::begin(digits), std::end(digits));
  return digits;
}

class Solution {
 public:
  std::vector<int> separateDigits(std::vector<int>& nums) {
    std::vector<int> result;
    for (auto n : nums) {
      auto const digs = get_digits(n);
      for (auto n : digs) {
        result.push_back(n);
      }
    }
    return result;
  }
};
