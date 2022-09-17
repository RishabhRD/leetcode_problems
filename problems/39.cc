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

void csum(std::vector<int> const& candidates, int i, std::vector<int>& cur,
          std::vector<std::vector<int>>& res, int target) {
  if (i > std::size(candidates) - 1) return;
  if (target < 0) return;
  if (target == 0) {
    res.push_back(cur);
    return;
  }
  cur.push_back(candidates[i]);
  csum(candidates, i, cur, res, target - candidates[i]);
  cur.pop_back();
  csum(candidates, i + 1, cur, res, target);
}

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    std::vector<int> cur;
    std::vector<std::vector<int>> res;
    csum(candidates, 0, cur, res, target);
    return res;
  }
};
