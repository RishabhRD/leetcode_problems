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
  int maximumRobots(std::vector<int> const& chargeTimes,
                    std::vector<int> const& runningCosts, long long budget) {
    auto const n = std::size(chargeTimes);

    long long ans = 0;
    int low = 0;
    long long charge_cur_cost = 0;
    long long running_cur_cost = 0;
    long long running_sum = 0;

    std::deque<int> dq;
    for (int high = 0; high < n; ++high) {
      long long k = high - low + 1;
      running_cur_cost += running_sum;
      running_cur_cost += k * runningCosts[high];
      running_sum += runningCosts[high];

      auto const old_charge_max = dq.empty() ? 0 : chargeTimes[dq.front()];
      while (not dq.empty() and chargeTimes[dq.back()] < chargeTimes[high]) {
        dq.pop_back();
      }
      dq.push_back(high);
      auto const new_charge_max = chargeTimes[dq.front()];
      charge_cur_cost -= old_charge_max;
      charge_cur_cost += new_charge_max;

      auto total_cost = running_cur_cost + charge_cur_cost;

      while (total_cost > budget) {
        running_cur_cost -= running_sum;
        running_cur_cost -= (k - 1) * runningCosts[low];
        running_sum -= runningCosts[low];

        if (dq.front() == low) {
          auto const old_max = chargeTimes[dq.front()];
          dq.pop_front();
          auto const new_max = dq.empty() ? 0 : chargeTimes[dq.front()];
          charge_cur_cost -= old_max;
          charge_cur_cost += new_max;
        }

        total_cost = running_cur_cost + charge_cur_cost;
        ++low;
        k = high - low + 1;
      }
      ans = std::max(ans, k);
    }
    return ans;
  }
};
