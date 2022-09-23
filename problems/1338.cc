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
  int minSetSize(std::vector<int>& arr) {
    std::unordered_map<int, int> freq_mp;
    for (auto n : arr) ++freq_mp[n];
    auto const n = std::size(arr);
    std::vector freq_count(n + 1, 0);
    for (auto [k, v] : freq_mp) ++freq_count[v];
    int cur = 0;
    int num = 0;
    for (int i = n; i >= 0; --i) {
      while (freq_count[i]--) {
        cur += i;
        ++num;
        if (cur >= n - cur) return num;
      }
    }
    return num;
  }
};
