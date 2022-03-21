#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

template<typename Iter, typename Value>
int right_distance(Iter begin, Iter end, Value v, int not_found_val) {
  auto const iter_loc = std::find(begin, end, v);
  if (iter_loc == end) return not_found_val;
  return std::distance(begin, iter_loc);
}

class Solution {
public:
  vector<int> shortestToChar(string const s, char c) {
    int const n = size(s);
    int left_dist = n * 2;
    auto const end = std::end(s);
    auto cur = std::begin(s);
    int right_dist = right_distance(cur, end, c, n * 2);
    vector<int> res;
    while (cur != end) {
      res.push_back(min(left_dist, right_dist));
      ++cur;
      if (right_dist == 0) {
        left_dist = 1;
        right_dist = right_distance(cur, end, c, n * 2);
      } else {
        ++left_dist;
        --right_dist;
      }
    }
    return res;
  }
};
