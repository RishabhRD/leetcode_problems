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
  int hardestWorker(int n, std::vector<std::vector<int>>& logs) {
    int highest = logs[0][0];
    int max_work = logs[0][1];
    for (int i = 1; i < std::size(logs); ++i) {
      if (logs[i][1] - logs[i - 1][1] > max_work) {
        highest = logs[i][0];
        max_work = logs[i][1] - logs[i - 1][1];
      } else if (logs[i][1] - logs[i - 1][1] == max_work) {
        highest = std::min(highest, logs[i][0]);
      }
    }
    return highest;
  }
};
