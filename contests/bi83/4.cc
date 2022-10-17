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
  int shortestSequence(std::vector<int> const& rolls, int k) {
    std::unordered_set<int> st;
    int res = 0;
    for (auto ele : rolls) {
      st.insert(ele);
      if (st.size() == k) {
        st.clear();
        ++res;
      }
    }
    return res + 1;
  }
};
