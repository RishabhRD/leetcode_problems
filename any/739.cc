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
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    const int n = size(temperatures);
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
      while (not empty(st) and temperatures[st.top()] <= temperatures[i]) {
        st.pop();
      }
      if (empty(st))
        res[i] = 0;
      else
        res[i] = st.top() - i;
      st.push(i);
    }
    return res;
  }
};
