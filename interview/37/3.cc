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

int dfs(string_view s, int cur_idx, vector<int>& dp) {
  if (cur_idx >= size(s)) { return 1; }
  if (dp[cur_idx] != -1) return dp[cur_idx];
  int cnt = 0;
  if (s[cur_idx] >= '1' and s[cur_idx] <= '9') {// one digit
    cnt += dfs(s, cur_idx + 1, dp);
  }
  if (cur_idx + 1 < size(s)) {
    if ((s[cur_idx] == '1') or (s[cur_idx] == '2' and s[cur_idx + 1] <= '6')) {
      cnt += dfs(s, cur_idx + 2, dp);
    }
  }
  return dp[cur_idx] = cnt;
}

class Solution {
public:
  int numDecodings(string s) {
    const int n = size(s);
    vector<int> dp(n, -1);
    return dfs(s, 0, dp);
  }
};

int main(){
  Solution sol;
  cout << sol.numDecodings("111111111111111111111111111111111111111111111") << endl;
}
