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

void make_subset(int const cur_idx,
  vector<int> const &nums,
  vector<int> &cur,
  vector<vector<int>> &res) {
  if (cur_idx == size(nums)) {
    res.push_back(cur);
    return;
  }
  make_subset(cur_idx + 1, nums, cur, res);
  cur.push_back(nums[cur_idx]);
  make_subset(cur_idx + 1, nums, cur, res);
  cur.pop_back();
}

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> cur;
    vector<vector<int>> res;
    make_subset(0, nums, cur, res);
    return res;
  }
};
