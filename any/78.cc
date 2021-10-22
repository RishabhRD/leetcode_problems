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

template <typename Iter>
void make_subset(Iter cur_ele, Iter end, vector<int>& cur_set, vector<vector<int>>& final_set){
  if(cur_ele == end){
    final_set.push_back(cur_set);
    return;
  }
  cur_set.push_back(*cur_ele);
  make_subset(next(cur_ele), end, cur_set, final_set);
  cur_set.pop_back();
  make_subset(next(cur_ele), end, cur_set, final_set);
}


class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> cur_set;
    vector<vector<int>> final_set;
    make_subset(cbegin(nums), cend(nums), cur_set, final_set);
    return final_set;
  }
};
