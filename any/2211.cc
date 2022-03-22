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

class Solution {
public:
  int countCollisions(string const directions) {
    auto first = find_if(
      cbegin(directions), cend(directions), [](auto c) { return c != 'L'; });
    auto r_last = find_if(
      crbegin(directions), crend(directions), [](auto c) { return c != 'R'; });
    return count_if(first, r_last.base(), [](auto c) { return c != 'S'; });
  }
};
