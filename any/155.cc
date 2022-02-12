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

class MinStack {
  stack<pair<int, int>> st;

public:
  MinStack() {}
  void push(int val) {
    if (st.empty()) {
      st.emplace(val, val);
    } else {
      st.emplace(val, min(st.top().second, val));
    }
  }

  void pop() { st.pop(); }

  int top() { return st.top().first; }

  int getMin() { return st.top().second; }
};
