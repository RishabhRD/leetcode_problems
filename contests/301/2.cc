#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class SmallestInfiniteSet {
  std::set<int> st;

 public:
  SmallestInfiniteSet() {
    for (int i = 1; i <= 1000; ++i) st.insert(i);
  }

  int popSmallest() {
    if (st.empty()) {
      return -1;
    }
    auto const first = *st.begin();
    st.erase(first);
    return first;
  }

  void addBack(int num) { st.insert(num); }
};
