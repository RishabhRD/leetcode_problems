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

class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    if (b > a) return maximumScore(b, a, c);
    if (c > b) return maximumScore(a, c, b);
    if (b == 0) return 0;
    return 1 + maximumScore(a - 1, b - 1, c);
  }
};
