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

enum class side_type { start, end };

struct skyline_point {
  int x;
  int height;
  side_type type;
};

struct skyline_cmp {
  bool operator()(skyline_point p1, skyline_point p2) const {
    if (p1.x < p2.x) {
      return true;
    } else if (p1.x == p2.x) {
      if (p1.type == side_type::start and p2.type == side_type::start) {
        return p1.height > p2.height;
      } else if (p1.type == side_type::end and p2.type == side_type::end) {
        return p1.height < p2.height;
      } else {
        return p1.type == side_type::start;
      }
    } else {
      return false;
    }
  }
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    set<skyline_point, skyline_cmp> st;
    for (auto const &building : buildings) {
      st.insert({ building[0], building[2], side_type::start });
      st.insert({ building[1], building[2], side_type::end });
    }
    vector<vector<int>> res;
    map<int, int> height_set;
    auto insert = [&](int ele) { height_set[ele]++; };
    auto erase = [&](int ele) {
      height_set[ele]--;
      if (height_set[ele] == 0) height_set.erase(ele);
    };
    auto get_max_height = [&] { return rbegin(height_set)->first; };
    insert(0);
    for (auto const point : st) {
      auto old_max = get_max_height();
      if (point.type == side_type::start) {
        insert(point.height);
      } else {
        erase(point.height);
      }
      auto new_max = get_max_height();
      if (old_max != new_max) { res.push_back(vector({ point.x, new_max })); }
    }
    return res;
  }
};
