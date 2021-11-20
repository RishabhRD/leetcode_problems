#include <queue>
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
  int maxDistance(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    const int n = size(grid);
    int water = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) { q.emplace(i, j); }
        else water++;
      }
    }
    if(water == 0) return -1;
    int level = -1;
    while (not empty(q)) {
      int sz = size(q);
      while (sz--) {
        const auto [x, y] = q.front();
        q.pop();
        constexpr static int dx[] = { 1, -1, 0, 0 };
        constexpr static int dy[] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
          const int new_x = x + dx[i];
          const int new_y = y + dy[i];
          if (new_x >= 0 and new_y >= 0 and new_x < n and new_y < n) {
            if (grid[new_x][new_y] != 1) {
              grid[new_x][new_y] = 1;
              q.emplace(new_x, new_y);
            }
          }
        }
      }
      level++;
    }
    return level;
  }
};
