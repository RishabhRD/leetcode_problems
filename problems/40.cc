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

void csum(std::vector<int> const& candidates, int i, int target,
          std::vector<int>& cur, std::vector<std::vector<int>>& res) {
  if (target == 0) {
    res.push_back(cur);
    return;
  }
  if (target < 0) return;
  for (int j = i; j < std::size(candidates); ++j) {
    if (j > i and candidates[j] == candidates[j - 1]) continue;
    cur.push_back(candidates[j]);
    csum(candidates, j + 1, target - candidates[j], cur, res);
    cur.pop_back();
  }
}

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> cur;
    std::sort(std::begin(candidates), std::end(candidates));
    csum(candidates, 0, target, cur, res);
    return res;
  }
};
