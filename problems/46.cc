#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

void perm(vector<int> const &nums,
  vector<int> &cur_list,
  vector<vector<int>> &res) {
  if (size(cur_list) == size(nums)) {
    res.push_back(cur_list);
    return;
  }
  for (int const num : nums) {
    if (std::find(cbegin(cur_list), cend(cur_list), num) != cend(cur_list))
      continue;
    cur_list.push_back(num);
    perm(nums, cur_list, res);
    cur_list.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> cur;
    perm(nums, cur, res);
    return res;
  }
};
