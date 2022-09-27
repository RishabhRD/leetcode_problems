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

struct task {
  int arrival;
  int idx;
  int time_taken;
};

auto compare_by_arrival = [](task a, task b) { return a.arrival < b.arrival; };

auto compare_by_time_taken = [](task a, task b) {
  if (a.time_taken == b.time_taken) return a.idx > b.idx;
  return a.time_taken > b.time_taken;
};

auto make_tasks(std::vector<std::vector<int>> const& tasks) {
  std::vector<task> res(std::size(tasks));
  for (int i = 0; i < std::size(tasks); ++i) {
    res[i] = task{tasks[i][0], i, tasks[i][1]};
  }
  std::sort(std::begin(res), std::end(res), compare_by_arrival);
  return res;
}

class Solution {
 public:
  std::vector<int> getOrder(std::vector<std::vector<int>>& t) {
    auto const tasks = make_tasks(t);
    auto const n = std::size(tasks);
    std::vector<int> res;
    std::priority_queue<task, std::vector<task>,
                        decltype(compare_by_time_taken)>
        pq(compare_by_time_taken);
    long long cur_time = -1;
    int i = 0;
    while (i < n or not std::empty(pq)) {
      if (pq.empty()) {
        cur_time = std::max(static_cast<long long>(tasks[i].arrival), cur_time);
      }
      while (i < n and tasks[i].arrival <= cur_time) {
        pq.push(tasks[i++]);
      }

      auto [arrival_time, idx, time_taken] = pq.top();
      pq.pop();
      res.push_back(idx);
      cur_time += time_taken;
    }
    return res;
  }
};
