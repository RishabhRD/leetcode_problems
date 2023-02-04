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
  long long countQuadruplets(std::vector<int>& nums) {
    ll const n = nums.size();
    std::vector less_than(n + 1, std::vector<ll>(n + 1, 0));
    for (ll j = 1; j <= n; ++j) {
      for (ll i = 1; i <= n; ++i) {
        less_than[i][j] = less_than[i - 1][j] + (nums[i - 1] < j);
      }
    }
    std::vector greater_than(n + 1, std::vector<ll>(n + 1, 0));
    for (ll j = 1; j <= n; ++j) {
      for (ll i = 1; i <= n; ++i) {
        greater_than[i][j] = greater_than[i - 1][j] + (nums[n - i] > j);
      }
    }
    ll res = 0;
    for (ll j = 0; j < n; ++j) {
      for (ll k = j + 1; k < n; ++k) {
        if (nums[k] < nums[j]) {
          ll const potential_i = less_than[j][nums[k]];
          ll const potential_l = greater_than[n - k - 1][nums[j]];
          res += potential_i * potential_l;
        }
      }
    }
    return res;
  }
};
