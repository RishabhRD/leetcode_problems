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

int count_num_alives(vector<vector<int>> const &board, int i, int j) {
  int num_alive = 0;
  constexpr static pair<int, int> d[] = {
    { -1, -1 },
    { -1, 0 },
    { -1, 1 },
    { 0, -1 },
    { 0, 1 },
    { 1, -1 },
    { 1, 0 },
    { 1, 1 },
  };
  for (auto [dx, dy] : d) {
    int const x = i + dx;
    int const y = j + dy;
    if (x >= 0 and y >= 0 and x < size(board) and y < size(board[0])) {
      num_alive += (board[x][y] == 1 or board[x][y] == 3);
    }
  }
  return num_alive;
}

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    int const m = size(board);
    int const n = size(board[0]);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        auto const num_alive = count_num_alives(board, i, j);
        if (board[i][j] == 0) {
          if (num_alive == 3) board[i][j] = 2;
        } else if (board[i][j] == 1) {
          if (num_alive < 2 or num_alive > 3) board[i][j] = 3;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 2)
          board[i][j] = 1;
        else if (board[i][j] == 3)
          board[i][j] = 0;
      }
    }
  }
};
