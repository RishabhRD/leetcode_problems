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
  vector<int> prevPermOpt1(vector<int> &arr) {
    auto left = is_sorted_until(rbegin(arr), rend(arr), greater<int>{});
    if (left != rend(arr)) {
      auto req_ele_itr = upper_bound(rbegin(arr), left, *left, greater<int>{});
      auto right = lower_bound(left.base(), req_ele_itr.base(), *req_ele_itr);
      iter_swap(left, right);
    }
    return arr;
  }
};
