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

struct worker_t {
  ll l2r;
  ll o;
  ll r2l;
  ll n;
  ll idx;
};

class Solution {
 public:
  int findCrossingTime(int n, int k, std::vector<std::vector<int>>& time) {
    std::vector<worker_t> worker;
    for (ll i = 0; i < k; ++i) {
      worker.push_back(
          worker_t{time[i][0], time[i][1], time[i][2], time[i][3], i});
    }
    auto eff_cmp = [&](int a, int b) {
      if (worker[a].l2r + worker[a].r2l == worker[b].l2r + worker[b].r2l)
        return worker[a].idx < worker[b].idx;
      else
        return worker[a].l2r + worker[a].r2l < worker[b].l2r + worker[b].r2l;
    };
    auto ttl_cmp = [](auto a, auto b) { return a.second > b.second; };
    std::priority_queue<int, std::vector<int>, decltype(eff_cmp)> left_waiting(
        eff_cmp);
    std::priority_queue<int, std::vector<int>, decltype(eff_cmp)> right_waiting(
        eff_cmp);
    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, decltype(ttl_cmp)> pickq(
        ttl_cmp);
    std::priority_queue<pii, std::vector<pii>, decltype(ttl_cmp)> putq(ttl_cmp);
    for (ll i = 0; i < k; ++i) left_waiting.push(i);
    ll cur_time = 0;
    ll done = 0;
    ll picked = 0;
    while (done < n) {
      while (pickq.size() && pickq.top().second <= cur_time) {
        auto const [w, ttl] = pickq.top();
        pickq.pop();
        // std::cout << w << " picked "
        //           << " till " << ttl << std::endl;
        right_waiting.push(w);
      }
      while (putq.size() && putq.top().second <= cur_time) {
        auto const [w, ttl] = putq.top();
        putq.pop();
        ++done;
        // std::cout << w << " put "
        //           << " till " << ttl << std::endl;
        left_waiting.push(w);
        if (done == n) return ttl - worker[w].n;
      }
      if (right_waiting.size()) {
        auto const w = right_waiting.top();
        right_waiting.pop();
        // std::cout << w << " crossing from right to left from " << cur_time
        //           << " to " << cur_time + worker[w].r2l << std::endl;
        cur_time += worker[w].r2l;
        putq.push({w, cur_time + worker[w].n});
      } else if (left_waiting.size() && picked < n) {
        auto const w = left_waiting.top();
        left_waiting.pop();
        // std::cout << w << " crossing from left to right from " << cur_time
        //           << " to " << cur_time + worker[w].l2r << std::endl;
        cur_time += worker[w].l2r;
        pickq.push({w, cur_time + worker[w].o});
        ++picked;
      } else {
        ++cur_time;
      }
    }
    return 0;
  }
};
