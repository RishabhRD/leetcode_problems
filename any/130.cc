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


void dfs(vector<vector<char>> &board, int x, int y, char val) {
  if (x < 0 or y < 0 or x >= size(board) or y >= size(board[0])) return;
  if (board[x][y] == 'X' or board[x][y] == val) return;
  board[x][y] = val;
  dfs(board, x + 1, y, val);
  dfs(board, x, y + 1, val);
  dfs(board, x - 1, y, val);
  dfs(board, x, y - 1, val);
}

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int const m = size(board);
    int const n = size(board[0]);
    for (int i = 0; i < m; i++) dfs(board, i, 0, '1');
    for (int i = 0; i < m; i++) dfs(board, i, n - 1, '1');
    for (int i = 0; i < n; i++) dfs(board, 0, i, '1');
    for (int i = 0; i < n; i++) dfs(board, m - 1, i, '1');
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (board[i][j] == 'O') board[i][j] = 'X';
      }
    }
    for (int i = 0; i < m; i++) dfs(board, i, 0, 'O');
    for (int i = 0; i < m; i++) dfs(board, i, n - 1, 'O');
    for (int i = 0; i < n; i++) dfs(board, 0, i, 'O');
    for (int i = 0; i < n; i++) dfs(board, m - 1, i, 'O');
  }
};

int main() {
  vector<vector<char>> vec{
    { 'X', 'O', 'X', 'X' },
    { 'O', 'X', 'O', 'X' },
    { 'X', 'O', 'X', 'O' },
    { 'O', 'X', 'O', 'X' },
    { 'X', 'O', 'X', 'O' },
    { 'O', 'X', 'O', 'X' },
  };
  Solution sol;
  sol.solve(vec);
}
