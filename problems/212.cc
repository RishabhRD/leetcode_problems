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

struct node {
  bool is_leaf;
  node *children[128]{ nullptr };
};

void add(node *nd, string_view word) {
  for (char c : word) {
    if (not nd->children[c]) { nd->children[c] = new node{ false }; }
    nd = nd->children[c];
  }
  nd->is_leaf = true;
}

void dfs(vector<vector<char>> &board,
  node *cur_node,
  string &cur_str,
  vector<string> &result,
  int x,
  int y) {
  if (cur_node->is_leaf) {
    result.push_back(string(cur_str));
    cur_node->is_leaf = false;
  }
  if (x < 0 or y < 0 or x >= size(board) or y >= size(board[0])
      or cur_node->children[board[x][y]] == nullptr)
    return;
  const char cur_char = board[x][y];
  board[x][y] = '*';
  cur_node = cur_node->children[cur_char];
  cur_str += cur_char;
  constexpr static int dx[] = { 0, 0, -1, 1 };
  constexpr static int dy[] = { -1, 1, 0, 0 };
  for (int i = 0; i < size(dx); i++) {
    dfs(board, cur_node, cur_str, result, x + dx[i], y + dy[i]);
  }
  cur_str.pop_back();
  board[x][y] = cur_char;
}

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    node *root = new node{ false };
    for (string_view str : words) { add(root, str); }
    vector<string> result;
    string str;
    for (int i = 0; i < size(board); i++) {
      for (int j = 0; j < size(board[0]); j++) {
        dfs(board, root, str, result, i, j);
      }
    }
    return result;
  }
};
