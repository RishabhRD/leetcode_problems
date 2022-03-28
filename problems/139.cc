#include <cmath>
#include <unordered_set>
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
  bool wordBreak(string s, vector<string> &wordDict) {
    int const n = size(s);
    unordered_set<string_view> const st{ begin(wordDict), end(wordDict) };
    vector dp(n + 1, false);
    dp[n] = true;
    string_view str = s;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        string_view check_str = str.substr(i, j - i + 1);
        dp[i] = dp[i] || ((st.find(check_str) != st.end()) && (dp[j + 1]));
      }
    }
    return dp[0];
  }
};
