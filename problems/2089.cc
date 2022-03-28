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
  vector<int> targetIndices(vector<int> const &nums, int target) {
    auto start = count_if(
      cbegin(nums), cend(nums), [target](auto num) { return num < target; });
    auto cnt = count(cbegin(nums), cend(nums), target);
    vector<int> res(cnt);
    iota(begin(res), end(res), start);
    return res;
  }
};
