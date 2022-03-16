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

class Solution {
public:
  vector<vector<int>> largeGroupPositions(string const s) {
    auto cur = std::begin(s);
    auto end = std::end(s);
    vector<vector<int>> res;
    while (cur != end) {
      auto const cur_ele = *cur;
      auto const next_ele =
        std::find_if(cur, end, [cur_ele](auto c) { return c != cur_ele; });
      auto const num_ele = std::distance(cur, next_ele);
      if (num_ele >= 3) {
        int const begin_pos = std::distance(begin(s), cur);
        int const end_pos = std::distance(begin(s), next_ele) - 1;
        res.push_back({ begin_pos, end_pos });
      }
      cur = next_ele;
    }
    return res;
  }
};
