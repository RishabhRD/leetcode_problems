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
  bool isMonotonic(vector<int> &nums) {
    return adjacent_find(cbegin(nums), cend(nums), greater<int>{}) == cend(nums)
           || adjacent_find(cbegin(nums), cend(nums), less<int>{})
                == cend(nums);
  }
};
