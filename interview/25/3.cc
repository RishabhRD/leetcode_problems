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

int cost(char from, char to) {
  return from == 26 ? 0 : abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}

int min_dist(const string_view word,
  const char left,
  const char right,
  const size_t pos,
  vector<vector<vector<int>>> &dp) {
  if (pos >= size(word)) return 0;
  if (dp[left][right][pos] == -1) {
    auto to = word[pos] - 'A';
    dp[left][right][pos] =
      min(cost(left, to) + min_dist(word, to, right, pos + 1, dp),
        cost(right, to) + min_dist(word, left, to, pos + 1, dp));
  }
  return dp[left][right][pos];
}

class Solution {
public:
  int minimumDistance(string word) {
    const auto n = size(word);
    vector dp(27, vector(27, vector(n, -1)));
    return min_dist(word, 26, 26, 0, dp);
  }
};
