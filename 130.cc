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

using ll = long long;

void dfs(std::vector<std::vector<char>>& board, ll x, ll y) {
  if (!(x >= 0 && x < std::size(board) && y >= 0 && y < std::size(board[0]))) {
    return;
  }
  if (board[x][y] == 'X') return;
  if (board[x][y] == '1') return;
  board[x][y] = '1';
  dfs(board, x + 1, y);
  dfs(board, x - 1, y);
  dfs(board, x, y + 1);
  dfs(board, x, y - 1);
}

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& board) {
    auto const m = std::size(board);
    auto const n = std::size(board[0]);
    for (ll i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (ll i = 0; i < n; ++i) {
      dfs(board, 0, i);
      dfs(board, m - 1, i);
    }
    for (ll i = 0; i < m; ++i) {
      for (ll j = 0; j < n; ++j) {
        if (board[i][j] == 'O') board[i][j] = 'X';
      }
    }
    for (ll i = 0; i < m; ++i) {
      for (ll j = 0; j < n; ++j) {
        if (board[i][j] == '1') board[i][j] = 'O';
      }
    }
  }
};
