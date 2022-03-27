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
    vector<int> res;
    for (auto num : nums) {
      if (size(res) % 2 == 0 or num != res.back()) {
        res.push_back(num);
      }
    }
    return size(nums) - size(res) + size(res) % 2;
  }
};
