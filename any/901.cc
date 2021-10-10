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


class StockSpanner {
  stack<pair<int, int>> st;

public:
  StockSpanner() {}

  int next(int price) {
    int cur = 1;
    while(not empty(st) and st.top().first <= price){
      cur += st.top().second;
      st.pop();
    }
    st.emplace(price, cur);
    return cur;
  }
};
