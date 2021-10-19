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

bool contains(const unordered_set<string_view>& st, string_view str){
  return st.find(str) != end(st);
}

bool word_break(string_view str, const unordered_set<string_view>& st, size_t cur_idx, vector<int>& dp){
  if(cur_idx == size(str)) return true;
  if(dp[cur_idx] != -1) return dp[cur_idx];
  for(size_t i = cur_idx; i < size(str); i++){
    if(contains(st, str.substr(cur_idx, i - cur_idx + 1))){
      if(word_break(str, st, i + 1, dp)){
        return dp[cur_idx] = true;
      }
    }
  }
  return dp[cur_idx] = false;
}

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string_view> st{cbegin(wordDict), cend(wordDict)};
    vector<int> dp(size(s), -1);
    return word_break(s, st, 0, dp);
  }
};
