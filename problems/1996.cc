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
  int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
    std::sort(std::begin(properties), std::end(properties),
              [](auto const& a, auto const& b) {
                if (a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
              });
    std::stack<int> st;
    int ans = 0;
    for (auto const& vec : properties) {
      auto const val = vec[1];
      while (not st.empty() and st.top() < val) {
        st.pop();
        ++ans;
      }
      st.push(val);
    }
    return ans;
  }
};
