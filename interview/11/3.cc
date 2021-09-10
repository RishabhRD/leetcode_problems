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

bool is_interleave(const string &s1,
  const string &s2,
  const string &s3,
  int cur_s1,
  int cur_s2,
  int cur_s3,
  vector<vector<int>> &dp) {
  if (cur_s3 == size(s3) and cur_s1 == size(s1) and cur_s2 == size(s2))
    return true;
  if (dp[cur_s1][cur_s2] != -1) return dp[cur_s1][cur_s2];
  bool res = false;
  if (cur_s1 >= size(s1)) {
    if (s2[cur_s2] == s3[cur_s3])
      res = is_interleave(s1, s2, s3, cur_s1, cur_s2 + 1, cur_s3 + 1, dp);
    else
      res = false;
  } else if (cur_s2 >= size(s2)) {
    if (s1[cur_s1] == s3[cur_s3]) {
      res = is_interleave(s1, s2, s3, cur_s1 + 1, cur_s2, cur_s3 + 1, dp);
    } else {
      res = false;
    }
  } else if (s1[cur_s1] == s3[cur_s3] and s2[cur_s2] == s3[cur_s3]) {
    res = is_interleave(s1, s2, s3, cur_s1 + 1, cur_s2, cur_s3 + 1, dp)
          or is_interleave(s1, s2, s3, cur_s1, cur_s2 + 1, cur_s3 + 1, dp);
  } else if (s1[cur_s1] == s3[cur_s3]) {
    res = is_interleave(s1, s2, s3, cur_s1 + 1, cur_s2, cur_s3 + 1, dp);
  } else if (s2[cur_s2] == s3[cur_s3]) {
    res = is_interleave(s1, s2, s3, cur_s1, cur_s2 + 1, cur_s3 + 1, dp);
  } else {
    res = false;
  }
  return dp[cur_s1][cur_s2] = res;
}

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (size(s1) + size(s2) != size(s3)) return false;
    vector<vector<int>> dp(size(s1) + 1, vector<int>(size(s2) + 1, -1));
    return is_interleave(s1, s2, s3, 0, 0, 0, dp);
  }
};

int main() {
  Solution sol;
  cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}
