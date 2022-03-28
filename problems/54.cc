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

enum class direction_t { left, right, up, down };

pair<int, int> to_point(direction_t dir) {
  switch (dir) {
  case direction_t::left:
    return { 0, -1 };
  case direction_t::right:
    return { 0, 1 };
  case direction_t::up:
    return { -1, 0 };
  default:
    return { 1, 0 };
  };
}

auto next_point_in_dir(pair<int, int> cur_point, direction_t cur_dir) {
  auto [cur_x, cur_y] = cur_point;
  auto [dx, dy] = to_point(cur_dir);
  return pair{ cur_x + dx, cur_y + dy };
}

auto next_direction(direction_t cur_dir) {
  switch (cur_dir) {
  case direction_t::right:
    return direction_t::down;
  case direction_t::down:
    return direction_t::left;
  case direction_t::left:
    return direction_t::up;
  default:
    return direction_t::right;
  };
}

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    auto cur_dir = direction_t::right;
    const int m = size(matrix);
    const int n = size(matrix[0]);
    vector visited(m, vector(n, false));
    auto is_valid_point = [&](auto point) {
      auto const [x, y] = point;
      return x >= 0 and x < m and y >= 0 and y < n and (!visited[x][y]);
    };
    auto cur_point = pair{ 0, 0 };
    vector<int> res;
    while (true) {
      auto const [x, y] = cur_point;
      res.push_back(matrix[x][y]);
      visited[x][y] = true;
      auto const new_point = next_point_in_dir(cur_point, cur_dir);
      if (!is_valid_point(new_point)) {
        cur_dir = next_direction(cur_dir);
        auto const new_point = next_point_in_dir(cur_point, cur_dir);
        if (!is_valid_point(new_point)) {
          break;
        } else {
          cur_point = new_point;
        }
      } else {
        cur_point = new_point;
      }
    }
    return res;
  }
};
