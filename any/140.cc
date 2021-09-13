#include <unordered_map>
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

vector<string> dfs(string s, const vector<string>& wordDict, unordered_map<string, vector<string>>& mp){
  if(mp.find(s) != mp.end()){
    return mp[s];
  }
  vector<string> res;
  if(size(s) == 0){
    res.push_back("");
    return res;
  }
  for(const auto& word : wordDict){
    if(s.find(word) == 0){
      for(auto str : dfs(s.substr(size(word)), wordDict, mp)){
        res.push_back(word + (empty(str) ? "" : " ") + str);
      }
    }
  }
  mp[s] = res;
  return res;
}

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_map<string, vector<string>> mp;
    return dfs(s, wordDict, mp);
  }
};
