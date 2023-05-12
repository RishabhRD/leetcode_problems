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

using ll = long long;

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    ll low = 0;
    std::deque<ll> st;
    std::vector<int> res;
    for (ll high = 0; high < nums.size(); ++high) {
      while (st.size() && nums[st.back()] < nums[high]) {
        st.pop_back();
      }
      st.push_back(high);
      while (high - low + 1 > k) {
        if (st.front() <= low) {
          st.pop_front();
        }
        ++low;
      }

      if (high - low + 1 == k) {
        res.push_back(nums[st.front()]);
      }
    }
    return res;
  }
};
