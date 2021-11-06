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

void all_set(vector<int> &nums,
  int i,
  vector<int> &cur,
  vector<vector<int>> &res) {
  if (i == size(nums)) {
    res.push_back(cur);
    return;
  }
  all_set(nums, i + 1, cur, res);
  cur.push_back(nums[i]);
  all_set(nums, i + 1, cur, res);
  cur.pop_back();
}
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> cur;
    all_set(nums, 0, cur, res);
    return res;
  }
};
