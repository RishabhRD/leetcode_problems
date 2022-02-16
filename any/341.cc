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
  stack<pair<int, vector<NestedInteger> const *>> st;

  vector<NestedInteger> const *list;
  int idx;

public:
  NestedIterator(vector<NestedInteger> &nestedList)
    : list(&nestedList), idx(0) {}

  int next() {
    auto val = list->at(idx).getInteger();
    idx++;
    return val;
  }

  bool hasNext() {
    if (idx < list->size()) {
      auto &val = list->at(idx);
      if (val.isInteger()) {
        return true;
      } else {
        idx++;
        st.emplace(idx, list);
        idx = 0;
        list = &val.getList();
        return hasNext();
      }
    } else if (not empty(st)) {
      auto [old_idx, old_list] = st.top();
      st.pop();
      idx = old_idx;
      list = old_list;
      return hasNext();
    } else {
      return false;
    }
  }
};
