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
  int destroyTargets(std::vector<int>& nums, int space) {
    std::unordered_map<int, int> freq;
    for (auto const e : nums) ++freq[e % space];
    return *std::max_element(std::cbegin(nums), std::cend(nums),
                             [&](auto a, auto b) {
                               if (freq[a] == freq[b]) return a < b;
                               return freq[a] < freq[b];
                             });
  }
};
