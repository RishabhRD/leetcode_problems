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

char to_char(int num) {
  if (num == 0) return '0';
  if (num == 1) return '1';
  if (num == 2) return '2';
  if (num == 3) return '3';
  if (num == 4) return '4';
  if (num == 5) return '5';
  if (num == 6) return '6';
  if (num == 7) return '7';
  if (num == 8) return '8';
  if (num == 9) return '9';
  return 0;
}

char increment(char c) {
  auto num = c - '0';
  num = (num + 1) % 10;
  return to_char(num);
}

char decrement(char c) {
  auto num = c - '0';
  num = (num - 1 + 10) % 10;
  return to_char(num);
}

auto get_neighbors(std::string str) {
  std::vector<std::string> res;
  for (auto& c : str) {
    auto const orig = c;
    c = increment(c);
    res.push_back(str);
    c = orig;
    c = decrement(c);
    res.push_back(str);
    c = orig;
  }
  return res;
}

class Solution {
 public:
  int openLock(std::vector<std::string>& deadends, std::string target) {
    std::unordered_set<std::string> dead_set(std::begin(deadends),
                                             std::end(deadends));
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    q.push("0000");
    visited.insert("0000");
    ll cur_level = 0;
    while (not std::empty(q)) {
      auto sz = q.size();
      while (sz--) {
        auto const top = q.front();
        if (top == target) return cur_level;
        q.pop();
        if (dead_set.find(top) == dead_set.end()) {
          auto const neighbors = get_neighbors(top);
          for (auto n : neighbors) {
            if (visited.find(n) == visited.end()) {
              visited.insert(n);
              q.push(n);
            }
          }
        }
      }
      ++cur_level;
    }
    return -1;
  }
};
