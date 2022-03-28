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
  int orangesRotting(vector<vector<int>> &grid) {
    const int m = size(grid);
    const int n = size(grid[0]);
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          q.emplace(i, j);
        }else if(grid[i][j] == 1){
          fresh++;
        }
      }
    }
    int level = -1;
    while (not empty(q)) {
      int sz = size(q);
      while (sz--) {
        auto [x, y] = q.front();
        q.pop();
        constexpr static int dx[] = { -1, 1, 0, 0 };
        constexpr static int dy[] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
          const int new_x = dx[i] + x;
          const int new_y = dy[i] + y;
          if (new_x >= 0 and new_y >= 0 and new_x < m and new_y < n) {
            if (grid[new_x][new_y] == 1) {
              q.emplace(new_x, new_y);
              grid[new_x][new_y] = 2;
              fresh--;
            }
          }
        }
      }
      level++;
    }
    if(fresh > 0) return -1;
    if(level == -1) return 0;
    return level;
  }
};
