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

pair<int, int> get_next_dir(pair<int, int> cur_dir) {
  constexpr static auto right = pair{ 0, 1 };
  constexpr static auto down = pair{ 1, 0 };
  constexpr static auto left = pair{ 0, -1 };
  constexpr static auto up = pair{ -1, 0 };
  if (cur_dir == right)
    return down;
  else if (cur_dir == down)
    return left;
  else if (cur_dir == left)
    return up;
  else
    return right;
}

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    const int m = size(matrix);
    const int n = size(matrix[0]);
    vector visited(m, vector(n, false));
    auto cur_dir = pair{ 0, 1 };
    int x = 0, y = 0;
    vector<int> res;
    while (true) {
      res.push_back(matrix[x][y]);
      visited[x][y] = true;
      int new_x = x + cur_dir.first;
      int new_y = y + cur_dir.second;
      if (new_x >= 0 and new_y >= 0 and new_x < m and new_y < n and visited[new_x][new_y] == false) {
        x = new_x;
        y = new_y;
      } else {
        cur_dir = get_next_dir(cur_dir);
        new_x = x + cur_dir.first;
        new_y = y + cur_dir.second;
        if (new_x >= 0 and new_y >= 0 and new_x < m and new_y < n and visited[new_x][new_y] == false) {
          x = new_x;
          y = new_y;
        } else {
          break;
        }
      }
    }
    return res;
  }
};
