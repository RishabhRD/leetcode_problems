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
    unordered_set<string_view> st;
    for (const auto &s : wordDict) { st.insert(s); }
    auto contains = [&](const string_view &str) {
      return st.find(str) != end(st);
    };
    vector<bool> dp(size(s) + 1);
    dp[0] = true;
    string_view str = s;
    for (int i = 1; i <= size(str); i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] and contains(str.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[size(str)];
  }
};
