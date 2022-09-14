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
    std::vector<int> st;
    int num_chunks = std::size(arr);
    for (auto const num : arr) {
      if (not std::empty(st) and num < st.back()) {
        auto const to_push = st.back();
        while (not std::empty(st) and num < st.back()) {
          --num_chunks;
          st.pop_back();
        }
        st.push_back(to_push);
      } else {
        st.push_back(num);
      }
    }
    return num_chunks;
  }
};
