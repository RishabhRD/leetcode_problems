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

using ll = long long;

class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (sx < tx && sy < ty) {
      if (tx < ty)
        ty %= tx;
      else
        tx %= ty;
    }
    return (sx == tx && sy <= ty && (ty - sy) % sx == 0) ||
           (sy == ty && sx <= tx && (tx - sx) % sy == 0);
  }
};
