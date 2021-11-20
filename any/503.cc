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
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> st;
    const int n = size(nums);
    vector<int> res(n, -1);
    auto next_greater_routine = [&] {
      for (int i = n - 1; i >= 0; i--) {
        while (size(st) and nums[i] >= nums[st.top()]) { st.pop(); }
        if (not empty(st)) res[i] = nums[st.top()];
        st.push(i);
      }
    };
    next_greater_routine();
    next_greater_routine();
    return res;
  }
};
