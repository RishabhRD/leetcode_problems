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
  std::vector<long long> findPrefixScore(std::vector<int>& nums) {
    std::vector<ll> ans;
    ll max = 0;
    for (auto n : nums) {
      max = std::max<ll>(max, n);
      ans.push_back(n + max);
    }

    for (ll i = 1; i < nums.size(); ++i) {
      ans[i] += ans[i - 1];
    }
    return ans;
  }
};
