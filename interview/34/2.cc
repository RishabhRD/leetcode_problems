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

constexpr int digit(char c) { return c - '0'; }

void dfs(string_view digits,
  vector<string_view> &graph,
  int cur_idx,
  string &cur_str,
  vector<string> &res) {
  if (cur_idx == size(digits)) {
    res.push_back(cur_str);
    return;
  }
  for (auto c : graph[digit(digits[cur_idx])]) {
    cur_str.push_back(c);
    dfs(digits, graph, cur_idx + 1, cur_str, res);
    cur_str.pop_back();
  }
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if(empty(digits)) return {};
    vector<string_view> graph = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    string cur_str;
    vector<string> res;
    dfs(digits, graph, 0, cur_str, res);
    return res;
  }
};
