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

template <typename Predicate>
ll binary_search(ll low, ll high, Predicate&& predicate) {
  if (low >= high) return low;
  auto const mid = low + (high - low) / 2;
  if (predicate(mid)) {
    return binary_search(mid + 1, high, predicate);
  } else {
    return binary_search(low, mid, predicate);
  }
}

class Solution {
 public:
  long long minimumMoney(std::vector<std::vector<int>>& transactions) {
    std::sort(std::begin(transactions), std::end(transactions),
              [](auto const& a, auto const& b) {
                auto const a_dip = std::min(-a[0], a[1] - a[0] - b[0]);
                auto const b_dip = std::min(-b[0], b[1] - b[0] - a[0]);
                if (a_dip == b_dip) return a[0] > b[0];
                return a_dip < b_dip;
              });
    auto is_sufficient = [&](ll money) {
      for (auto const& t : transactions) {
        auto const cost = t[0];
        auto const cashback = t[1];
        if (money < cost) return false;
        money += (-cost + cashback);
      }
      return true;
    };
    return binary_search(0, 1e14, std::not_fn(is_sufficient));
  }
};
