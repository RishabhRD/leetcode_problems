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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int const n = size(gas);
    auto at = [&](int i) { return gas[i % n] - cost[i % n]; };
    int dist_covered = 0;
    int cur_sum = 0;
    for (int i = 0; i < 2 * n; i++) {
      cur_sum += at(i);
      if (cur_sum < 0) {
        cur_sum = 0;
        dist_covered = 0;
      } else {
        dist_covered++;
        if (dist_covered == n) { return (i - n + 1) % n; }
      }
    }
    return -1;
  }
};
