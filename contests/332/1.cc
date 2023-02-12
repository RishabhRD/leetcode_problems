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
  std::vector<ll> digits;
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  std::reverse(std::begin(digits), std::end(digits));
  return digits;
}

ll concat(ll a, ll b) {
  ll sum = a;
  auto const digits = get_digits(b);
  for (auto n : digits) {
    sum = sum * 10 + n;
  }
  return sum;
}

class Solution {
 public:
  long long findTheArrayConcVal(std::vector<int>& nums) {
    ll low = 0;
    ll high = nums.size() - 1;
    ll sum = 0;
    while (low <= high) {
      if (low == high) {
        // std::cout << nums[low] << std::endl;
        sum += nums[low];
      } else {
        // std::cout << concat(nums[low], nums[high]) << std::endl;
        sum += concat(nums[low], nums[high]);
      }
      ++low;
      --high;
    }
    // std::cout << std::endl;
    return sum;
  }
};
