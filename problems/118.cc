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
  vector<vector<int>> generate(int numRows) {
    vector dp(numRows, vector({ 1 }));
    for (int i = 1; i < numRows; i++) {
      int const n = i + 1;
      for (int j = 1; j < n - 1; j++) {
        dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
      }
      dp[i].push_back(1);
    }
    return dp;
  }
};

int main() {
  Solution sol;
  sol.generate(5);
}
