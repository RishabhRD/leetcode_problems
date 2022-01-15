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

int longest_dist(vector<vector<int>> const &matrix,
  int x,
  int y,
  vector<vector<int>> &cache) {
  if (cache[x][y] != -1) return cache[x][y];
  constexpr static pair<int, int> d[] = {
    { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
  };
  int max_neighbor_dist = 0;
  for (auto [dx, dy] : d) {
    int const new_x = x + dx;
    int const new_y = y + dy;
    if (new_x >= 0 and new_y >= 0 and new_x < size(matrix)
        and new_y < size(matrix[0]) and matrix[new_x][new_y] > matrix[x][y])
      max_neighbor_dist =
        max(max_neighbor_dist, longest_dist(matrix, x + dx, y + dy, cache));
  }
  return cache[x][y] = max_neighbor_dist + 1;
}

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int const m = size(matrix);
    int const n = size(matrix[0]);
    vector cached_dist(m, vector(n, -1));
    int max_dist_can_travel = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        max_dist_can_travel =
          max(max_dist_can_travel, longest_dist(matrix, i, j, cached_dist));
      }
    }
    return max_dist_can_travel;
  }
};
