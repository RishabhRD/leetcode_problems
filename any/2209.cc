#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
  int minimumWhiteTiles(string const floor, int num_carpets, int carpet_len) {
    auto const n = size(floor);
    vector<int> num_white(n);
    transform_inclusive_scan(
      begin(floor), end(floor), begin(num_white), std::plus<int>{}, [](auto c) {
        return c - '0';
      });
    vector dp(n + 1, vector(num_carpets + 1, 0));
    for (int i = 1; i <= n; ++i) { dp[i][0] = num_white[i - 1]; }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= num_carpets; ++j) {
        if (floor[i - 1] == '0')
          dp[i][j] = dp[i - 1][j];
        else if (i - carpet_len <= 0) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = min(dp[i - carpet_len][j - 1], 1 + dp[i - 1][j]);
        }
      }
    }
    return dp[n][num_carpets];
  }
};

int main() {
  Solution sol;
  cout << sol.minimumWhiteTiles("11111", 2, 3) << endl;
}
