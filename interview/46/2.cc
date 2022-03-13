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
  int numTimesAllBlue(vector<int> &flips) {
    int max_idx = 0;
    int to_fill = 0;
    int res = 0;
    for (int const idx : flips) {
      if (idx < max_idx)
        to_fill--;
      else {
        to_fill += (idx - max_idx - 1);
        max_idx = idx;
      }
      if (to_fill == 0) res++;
    }
    return res;
  }
};
