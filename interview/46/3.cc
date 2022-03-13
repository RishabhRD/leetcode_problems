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

class Skiplist {
  map<int, int> st;

public:
  Skiplist() {}

  bool search(int target) { return st.find(target) != st.end(); }

  void add(int num) { st[num]++; }

  bool erase(int num) {
    if (search(num)) {
      st[num]--;
      if (st[num] == 0) st.erase(num);
      return true;
    } else {
      return false;
    }
  }
};
