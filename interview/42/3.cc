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

auto get_left_smaller(vector<int> const &heights) {
  int const n = size(heights);
  vector res(n, 0);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (not empty(st) and heights[st.top()] >= heights[i]) { st.pop(); }
    if (not empty(st)) {
      res[i] = i - st.top() - 1;
    } else {
      res[i] = i;
    }
    st.push(i);
  }
  return res;
}

auto get_right_smaller(vector<int> const &heights) {
  int const n = size(heights);
  vector res(n, 0);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (not empty(st) and heights[st.top()] >= heights[i]) st.pop();
    if (not empty(st)) {
      res[i] = st.top() - i - 1;
    } else {
      res[i] = n - i - 1;
    }
    st.push(i);
  }
  return res;
}

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    auto const left_smaller = get_left_smaller(heights);
    auto const right_smaller = get_right_smaller(heights);
    int const n = size(heights);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, (left_smaller[i] + right_smaller[i] + 1) * heights[i]);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector heights{ 1, 1 };
  cout << sol.largestRectangleArea(heights) << endl;
}
