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

bool is_palin(string_view str, int low, int high) {
  while (low < high) {
    if (str[low++] != str[high--]) return false;
  }
  return true;
}

void dfs(string_view str,
  int start,
  vector<string> &cur,
  vector<vector<string>> &res) {
  if (start == size(str)) {
    res.push_back(cur);
    return;
  }
  for (int i = start; i < size(str); i++) {
    if (is_palin(str, start, i)) {
      cur.push_back(string{ str.substr(start, i - start + 1) });
      dfs(str, i + 1, cur, res);
      cur.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    dfs(s, 0, cur, res);
    return res;
  }
};

int main() {
  string s = "aab";
  Solution sol;
  sol.partition(s);
}
