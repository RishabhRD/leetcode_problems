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
  int maxChunksToSorted(std::vector<int>& arr) {
    std::stack<int> st;
    int ans = 0;
    for (auto num : arr) {
      if (not std::empty(st) and st.top() > num) {
        auto const to_push = st.top();
        while (not std::empty(st) and st.top() > num) {
          st.pop();
          --ans;
        }
        st.push(to_push);
      } else {
        st.push(num);
      }
      ++ans;
    }
    return ans;
  }
};
