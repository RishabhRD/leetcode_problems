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

bool dfs(vector<vector<char>> &board,
  string_view word,
  int cur_idx,
  int cur_x,
  int cur_y) {
  if (cur_idx == size(word)) return true;
  if (cur_x < 0 or cur_y < 0 or cur_x >= size(board) or cur_y >= size(board[0])
      or board[cur_x][cur_y] != word[cur_idx])
    return false;
  const char cur_char = board[cur_x][cur_y];
  board[cur_x][cur_y] = '*';
  bool ret = dfs(board, word, cur_idx + 1, cur_x - 1, cur_y)
    or dfs(board, word, cur_idx + 1, cur_x + 1, cur_y)
    or dfs(board, word, cur_idx + 1, cur_x, cur_y - 1)
    or dfs(board, word, cur_idx + 1, cur_x, cur_y + 1);
  board[cur_x][cur_y] = cur_char;
  return ret;
}

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    const int m = size(board);
    const int n = size(board[0]);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, word, 0, i, j)) return true;
      }
    }
    return false;
  }
};
