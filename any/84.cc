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

void remove_greater(stack<int> &st, vector<int> const &heights, int idx) {
  while (not empty(st) and heights[st.top()] >= heights[idx]) st.pop();
}

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int const n = size(heights);
    vector<int> left_smaller(n);
    stack<int> left_stack;
    stack<int> right_stack;
    vector<int> right_smaller(n);
    for (int i = 0; i < n; i++) {
      remove_greater(left_stack, heights, i);
      if (not empty(left_stack)) {
        left_smaller[i] = left_stack.top() + 1;
      } else {
        left_smaller[i] = 0;
      }
      left_stack.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
      remove_greater(right_stack, heights, i);
      if (not empty(right_stack)) {
        right_smaller[i] = right_stack.top() - 1;
      } else {
        right_smaller[i] = n - 1;
      }
      right_stack.push(i);
    }
    int max_area = 0;
    for (int i = 0; i < n; i++) {
      max_area =
        max(max_area, heights[i] * (right_smaller[i] - left_smaller[i] + 1));
    }
    return max_area;
  }
};
