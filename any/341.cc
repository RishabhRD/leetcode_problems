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

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};


class NestedIterator {
  stack<NestedInteger> st;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    fill_stack(nestedList);
  }

  int next() {
    auto top = st.top().getInteger();
    st.pop();
    return top;
  }

  bool hasNext() {
    while(not empty(st) and !st.top().isInteger()){
      auto top = st.top().getList();
      st.pop();
      fill_stack(top);
    }
    return not empty(st);
  }

  void fill_stack(vector<NestedInteger>& list){
    for(int i = size(list) - 1; i >= 0; i--){
      st.push(list[i]);
    }
  }
};
