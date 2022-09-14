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
  int carFleet(int target, std::vector<int> const& position,
               std::vector<int> const& speed) {
    auto const n = std::size(position);
    std::vector<std::pair<int, int>> pos_speed(n);
    for (int i = 0; i < n; ++i) {
      pos_speed[i] = {position[i], speed[i]};
    }
    std::sort(std::begin(pos_speed), std::end(pos_speed));

    std::vector<double> time;
    for (auto const [pos, speed] : pos_speed) {
      double const dist = target - pos;
      time.push_back(dist / speed);
    }

    std::vector actual_time = time;
    for (int i = n - 2; i >= 0; i--) {
      actual_time[i] = std::max(time[i], actual_time[i + 1]);
    }
    actual_time.erase(
        std::unique(std::begin(actual_time), std::end(actual_time)),
        std::end(actual_time));
    return actual_time.size();
  }
};
