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
  int numJewelsInStones(string jewels, string stones) {
    vector<int> cnt(128);
    for (auto c : jewels) { cnt[c]++; }
    int res = 0;
    for (auto c : stones) {
      if (cnt[c] > 0) { res++; }
    }
    return res;
  }
};
