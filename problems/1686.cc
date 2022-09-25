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

int sign(int val) {
  if (val < 0)
    return -1;
  else if (val == 0)
    return 0;
  else
    return 1;
}

class Solution {
 public:
  int stoneGameVI(std::vector<int> const& aliceValues,
                  std::vector<int> const& bobValues) {
    std::vector<int> idx(std::size(aliceValues));
    std::iota(std::begin(idx), std::end(idx), 0);
    std::sort(std::begin(idx), std::end(idx), [&](auto a, auto b) {
      return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
    });
    bool parity = true;
    int aliceSum = 0;
    int bobSum = 0;
    for (auto i : idx) {
      if (parity) {
        aliceSum += aliceValues[i];
      } else {
        bobSum += bobValues[i];
      }
      parity = !parity;
    }
    return sign(aliceSum - bobSum);
  }
};
