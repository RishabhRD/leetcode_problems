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
  int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
    std::sort(std::begin(meetings), std::end(meetings),
              [](auto const& a, auto const& b) { return a[0] < b[0]; });

    using ll = long long;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> unoccupied;
    using pii = std::pair<ll, ll>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>>
        current_meetings;

    for (int i = 0; i < n; ++i) {
      unoccupied.push(i);
    }

    std::vector<ll> num_meetings(n, 0);

    for (auto const& meeting : meetings) {
      long long const start = meeting[0];
      long long end = meeting[1];

      while (not empty(current_meetings) and
             current_meetings.top().first <= start) {
        auto const [cur_end, cur_n] = current_meetings.top();
        current_meetings.pop();
        unoccupied.push(cur_n);
      }
      if (unoccupied.empty()) {
        auto const [cur_end, cur_n] = current_meetings.top();
        auto const diff = cur_end - start;
        end = end + diff;
        current_meetings.pop();
        unoccupied.push(cur_n);
      }
      auto const cur_n = unoccupied.top();
      unoccupied.pop();
      current_meetings.push({end, cur_n});
      ++num_meetings[cur_n];
    }
    return std::max_element(std::cbegin(num_meetings),
                            std::cend(num_meetings)) -
           std::cbegin(num_meetings);
  }
};

// int main() {
//   Solution sol;
//   std::vector<std::vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
//   sol.mostBooked(2, meetings);
// }
