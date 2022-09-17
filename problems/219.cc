#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> st;
    int low = 0;
    for (int high = 0; high < std::size(nums); ++high) {
      if (high - low + 1 > k + 1) {
        st.erase(nums[low]);
        ++low;
      }
      if (st.find(nums[high]) != st.end()) return true;
      st.insert(nums[high]);
    }
    return false;
  }
};
