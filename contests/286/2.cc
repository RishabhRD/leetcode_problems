#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDeletion(vector<int>& nums) {
    bool even = true;
    int last = 0;
    auto const num = count_if(begin(nums), end(nums), [&](auto ele) {
      if (even or last != ele) {
        even = !even;
        last = ele;
        return true;
      }
      return false;
    });
    return size(nums) - num + num % 2;
  }
};
