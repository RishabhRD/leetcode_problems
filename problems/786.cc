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

auto division(double a, double b) { return a / b; }

class Solution {
 public:
  std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
    auto cmp = [&arr](auto a, auto b) {
      return division(a.first, arr[a.second]) >
             division(b.first, arr[b.second]);
    };

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);
    for (auto n : arr) {
      pq.push({n, arr.size() - 1});
    }

    for (int i = 0; i < k - 1; ++i) {
      auto const [first_num, second_idx] = pq.top();
      pq.pop();
      if (second_idx - 1 >= 0) pq.push({first_num, second_idx - 1});
    }
    auto const [kth_num, kth_den_idx] = pq.top();
    return {kth_num, arr[kth_den_idx]};
  }
};
