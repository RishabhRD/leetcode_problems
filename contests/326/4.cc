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
  std::vector<int> closestPrimes(int left, int right) {
    std::vector<bool> is_prime(right + 1, true);
    std::vector<ll> primes;
    for (ll i = 2; i <= right; ++i) {
      if (is_prime[i]) {
        if (i >= left) primes.push_back(i);
        for (ll j = i + i; j <= right; j += i) {
          is_prime[j] = false;
        }
      }
    }
    ll dist = INT32_MAX;
    std::vector<int> res(2, -1);
    for (ll i = 1; i < primes.size(); ++i) {
      auto const cur_dist = primes[i] - primes[i - 1];
      if (cur_dist < dist) {
        res[0] = primes[i - 1];
        res[1] = primes[i];
        dist = cur_dist;
      }
    }

    return res;
  }
};
