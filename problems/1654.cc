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

auto contains(std::unordered_set<int> const& st, int ele) {
  return st.find(ele) != st.end();
}

class Solution {
 public:
  int minimumJumps(std::vector<int>& forbidden, int a, int b, int x) {
    int const stop =
        std::max(a + b +
                     std::max(x, *std::max_element(std::begin(forbidden),
                                                   std::end(forbidden))),
                 5000);
    std::unordered_set<int> forward_st{std::begin(forbidden),
                                       std::end(forbidden)};
    std::unordered_set<int> backward_st{};
    std::queue<std::pair<int, bool>> q;
    q.push({0, true});
    forward_st.insert(0);

    auto put_item = [&](auto ele, bool to_minus = false) {
      auto const put_ele = to_minus ? -ele : ele;
      if (contains(forward_st, ele))
        return;
      else if (contains(backward_st, ele)) {
        q.push({put_ele, false});
      } else {
        q.push({put_ele, true});
      }
    };

    auto cur_level = 0;
    while (not q.empty()) {
      auto sz = std::size(q);
      while (sz--) {
        auto const [top, can_move_both] = q.front();
        auto const cur = std::abs(top);
        if (cur == x) return cur_level;
        q.pop();
        if (can_move_both) {
          auto const forward = cur + a;
          if (forward < stop) {
            put_item(forward);
            forward_st.insert(forward);
          }
        }

        if (top >= 0) {
          auto const backward = cur - b;
          if (backward > 0) {
            put_item(backward, true);
            backward_st.insert(backward);
          }
        }
      }
      ++cur_level;
    }
    return -1;
  }
};
