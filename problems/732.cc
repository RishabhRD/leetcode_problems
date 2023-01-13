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

class MyCalendarThree {
  std::map<ll, ll> cnt;

 public:
  MyCalendarThree() {}

  int book(int startTime, int endTime) {
    ++cnt[startTime];
    --cnt[endTime];
    ll cur = 0;
    ll max_cnt = 0;
    for (auto [_, c] : cnt) {
      cur += c;
      max_cnt = std::max(max_cnt, cur);
    }
    return max_cnt;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
