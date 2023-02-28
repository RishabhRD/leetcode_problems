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
  std::vector<int> divisibilityArray(std::string word, int m) {
    std::vector<int> res;
    ll cur = 0;
    for (auto c : word) {
      cur = (cur * 10 + (c - '0')) % m;
      if (cur == 0)
        res.push_back(1);
      else
        res.push_back(0);
    }
    return res;
  }
};
