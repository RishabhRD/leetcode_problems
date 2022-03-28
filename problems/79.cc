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

bool dfs(int x,
  int y,
  vector<vector<char>> &board,
  string const &word,
  int const cur) {
  if (cur == size(word)) return true;
  if (x < 0 or y < 0 or x >= size(board) or y >= size(board[0])) return false;
  if (board[x][y] != word[cur]) return false;
  board[x][y] = '*';
  auto const exists = dfs(x, y + 1, board, word, cur + 1)
                      || dfs(x, y - 1, board, word, cur + 1)
                      || dfs(x + 1, y, board, word, cur + 1)
                      || dfs(x - 1, y, board, word, cur + 1);
  board[x][y] = word[cur];
  return exists;
}

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int const m = size(board);
    int const n = size(board[0]);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(i, j, board, word, 0)) return true;
      }
    }
    return false;
  }
};
