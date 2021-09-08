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

static constexpr int MAX = 1e7;

int solve(const vector<int> &houses,
  vector<vector<int>> &dp,
  const int k,
  const int cur_house,
  const int cur_k) {
  if(cur_house == size(houses)){
    if(k == cur_k) return 0;
    return MAX;
  }
  if(k == cur_k) return MAX;
  if(dp[cur_house][cur_k] != -1) return dp[cur_house][cur_k];
  int answer = MAX;
  for(int i = cur_house; i < size(houses); i++){
    int median = houses[(cur_house + i) / 2];
    int cost = 0;
    for(int j = cur_house; j <= i; j++){
      cost += abs(houses[j] - median);
    }
    answer = min(answer, solve(houses, dp, k, i + 1, cur_k + 1) + cost);
  }
  return dp[cur_house][cur_k] = answer;
}

class Solution {
public:
  int minDistance(vector<int> &houses, const int k) {
    sort(begin(houses), end(houses));
    vector<vector<int>> dp(size(houses), vector<int>(k, -1));
    return solve(houses, dp, k, 0, 0);
  }
};
