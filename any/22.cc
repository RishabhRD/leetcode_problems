#include <unordered_set>
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

void add_paren(int const n,
  int const open,
  int const closed,
  string &cur_str,
  vector<string> &res) {
  if (size(cur_str) == 2 * n) {
    res.push_back(cur_str);
    return;
  }
  if (n > open) {
    cur_str += '(';
    add_paren(n, open + 1, closed, cur_str, res);
    cur_str.pop_back();
  }
  if (open > closed) {
    cur_str += ')';
    add_paren(n, open, closed + 1, cur_str, res);
    cur_str.pop_back();
  }
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    add_paren(n, 0, 0, cur, res);
    return res;
  }
};
