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
  int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int max_go = 0;
    int cur_bricks_used = 0;
    for (int i = 1; i < std::size(heights); ++i) {
      if (heights[i] > heights[i - 1]) {
        pq.push(heights[i] - heights[i - 1]);
        if (pq.size() > ladders) {
          auto top = pq.top();
          pq.pop();
          cur_bricks_used += top;
          if (cur_bricks_used > bricks) break;
        }
      }
      max_go = i;
    }
    return max_go;
  }
};
