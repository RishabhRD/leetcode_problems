#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int num_trees(int n, vector<optional<int>>& dp) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return 1;
  if (dp[n]) return dp[n].value();
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += num_trees(i - 1, dp) * num_trees(n - i, dp);
  }
  dp[n] = sum;
  return sum;
}

class Solution {
 public:
  int numTrees(int n) {
    vector<optional<int>> dp(n + 1);
    return num_trees(n, dp);
  }
};
