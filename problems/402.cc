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
  std::string removeKdigits(std::string num, int k) {
    int num_removed = 0;
    std::string st;
    for (auto c : num) {
      while (not std::empty(st) and st.back() > c and num_removed < k) {
        st.pop_back();
        ++num_removed;
      }
      st.push_back(c);
    }
    while (not std::empty(st) and num_removed < k) {
      st.pop_back();
      ++num_removed;
    }
    st.erase(std::begin(st), std::find_if(std::begin(st), std::end(st),
                                          [](auto c) { return c != '0'; }));
    if (st.empty()) st.push_back('0');
    return st;
  }
};
