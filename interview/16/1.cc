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

class Solution {
public:
  int countSubstrings(string s) {
    if (size(s) == 1) return 1;
    if (size(s) == 0) return 0;
    const int n = size(s);
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) { dp[i][i] = true; }
    for (int i = 0; i < n - 1; i++) {
      dp[i][i + 1] = (s[i] == s[i + 1] ? true : false);
    }
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        const int j = i + len - 1;
        if (s[i] == s[j]) { dp[i][j] = dp[i + 1][j - 1]; }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j]) { cnt++; }
      }
    }
    return cnt;
  }
};

int main(){
  Solution sol;
  cout << sol.countSubstrings("aaaaa") << endl;
}
