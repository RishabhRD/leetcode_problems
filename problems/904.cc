#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int> const& fruits) {
    unordered_map<int, int> st;
    size_t i{};
    auto const n = size(fruits);
    size_t len{};
    for (size_t j{}; j < n; ++j) {
      ++st[fruits[j]];
      while (size(st) > 2) {
        --st[fruits[i]];
        if (st[fruits[i]] == 0) st.erase(fruits[i]);
        ++i;
      }
      len = max(len, j - i + 1);
    }
    return len;
  }
};
