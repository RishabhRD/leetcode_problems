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

class Solution {
public:
  int numDecodings(string s) {
    auto contains = [](char c1, char c2) {
      return (c1 == '1') || (c1 == '2' && c2 <= '6');
    };
    auto contains_char = [](char c) { return c != '0'; };

    const int n = size(s);
    int dp0 = 1;
    int dp1 = contains_char(s[0]) ? 1 : 0;

    for (int i = 2; i <= n; i++) {
      int new_dp{ 0 };
      if (contains_char(s[i - 1])) new_dp += dp1;
      if (contains(s[i - 2], s[i - 1])) new_dp += dp0;
      dp0 = dp1;
      dp1 = new_dp;
    }
    return dp1;
  }
};

int main() {
  Solution sol;
  string s = "226";
  cout << sol.numDecodings(s) << endl;
}
