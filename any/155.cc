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
  int min_val = INT32_MAX;
public:
    MinStack() {}
    
    void push(int val) {
      if(empty(st)){
        st.emplace(val, val);
      }else{
        st.emplace(val, min(val, st.top().second));
      }
    }
    
    void pop() {
      st.pop();
    }
    
    int top() {
      return st.top().first;
    }
    
    int getMin() {
      return st.top().second;
    }
};
