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

auto diff(std::string_view a, std::string_view b) {
  ll diff = 0;
  for (ll i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) ++diff;
  }
  return diff;
}

class Solution {
 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList) {
    std::unordered_set<std::string> visited{beginWord};
    std::queue<std::string> q({beginWord});
    ll cur = 1;
    while (not std::empty(q)) {
      auto sz = q.size();
      while (sz--) {
        auto const top = q.front();
        if (top == endWord) return cur;
        q.pop();
        for (std::string const& n : wordList) {
          if (diff(top, n) != 1) continue;
          if (visited.count(n)) continue;
          visited.insert(n);
          q.push(n);
        }
      }
      ++cur;
    }
    return 0;
  }
};
