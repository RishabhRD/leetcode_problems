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
  int countPairs(vector<int> const& nums, int k) {
    int cnt{0};
    for (int i = 0; i < size(nums); ++i) {
      for (int j = i + 1; j < size(nums); ++j) {
        if (nums[i] == nums[j] and (i * j) % k == 0) {
          ++cnt;
        }
      }
    }
    return cnt;
  }
};
