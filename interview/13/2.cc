#include <unordered_map>
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

bool is_valid(const vector<char> &vec) {
  unordered_map<char, int> mp;
  for (auto x : vec) {
    if (x == '.') continue;
    mp[x]++;
    if (mp[x] > 1) return false;
  }
  return true;
}

bool is_valid_rows(const vector<vector<char>> &vec) {
  for (const auto &x : vec) {
    if (!is_valid(x)) { return false; }
  }
  return true;
}

bool is_valid_columns(const vector<vector<char>> &vec) {
  for (int j = 0; j < 9; j++) {
    vector<char> in_vec;
    for (int i = 0; i < 9; i++) { in_vec.push_back(vec[i][j]); }
    if (!is_valid(in_vec)) { return false; }
  }
  return true;
}

vector<char> create_box_vector(const vector<vector<char>> &vec, int i, int j) {
  vector<char> my_vec;
  for (int i_incr = 0; i_incr < 3; i_incr++) {
    for (int j_incr = 0; j_incr < 3; j_incr++) {
      my_vec.push_back(vec[i + i_incr][j + j_incr]);
    }
  }
  return my_vec;
}

bool is_valid_boxes(const vector<vector<char>> &vec) {
  static constexpr pair<int, int> points[] = { { 0, 0 },
    { 3, 0 },
    { 6, 0 },
    { 0, 3 },
    { 3, 3 },
    { 6, 3 },
    { 0, 6 },
    { 3, 6 },
    { 6, 6 } };
  for (const auto [i, j] : points) {
    if (!is_valid(create_box_vector(vec, i, j))) { return false; }
  }
  return true;
}

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    return is_valid_rows(board) && is_valid_columns(board)
           && is_valid_boxes(board);
  }
};
