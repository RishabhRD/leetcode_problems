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

class DataStream {
  ll value;
  ll k;
  ll cur;

 public:
  DataStream(int value, int k) : value(value), k(k), cur(0) {}

  bool consec(int num) {
    if (num == value)
      ++cur;
    else
      cur = 0;
    return cur >= k;
  }
};
