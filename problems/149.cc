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

auto slope(vector<int> const &p1, vector<int> const &p2) {
  auto const dy = p1[1] - p2[1];
  auto const dx = p1[0] - p2[0];
  if (dx == 0) return numeric_limits<double>::infinity();
  return static_cast<double>(dy) / dx;
}

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int max_points = 1;
    int const n = size(points);
    for (int i = 0; i < n; i++) {
      unordered_map<double, int> slope_counts;
      for (int j = i + 1; j < n; j++) {
        auto const p_slope = slope(points[i], points[j]);
        slope_counts[p_slope]++;
      }
      int max_points_cur = 0;
      for (auto [k, v] : slope_counts) {
        max_points_cur = max(max_points_cur, v);
      }
      max_points = max(max_points, max_points_cur + 1);
    }
    return max_points;
  }
};
