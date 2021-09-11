#include <unordered_set>
#include <sstream>
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
  bool wordBreak(const string s, const vector<string> &wordDict) {
    unordered_set<string> mp;
    for(const auto& str : wordDict){
      mp.insert(str);
    }
    auto contains = [&](const string& str){
      cout << str << " " << (mp.find(str) != mp.end()) << endl;
      return mp.find(str) != mp.end();
    };
    vector<bool> dp(size(s) + 1);
    dp[0] = true;
    for(int i = 1; i <= size(s); i++){
      for(int j = 0; j < i; j++){
        if(dp[j] and contains(s.substr(j, i))) {
          dp[i] = true;
          break;
        }
      }
    }
    for(auto x : dp){
      cout << x << " ";
    }
    cout << endl;
    return dp[size(s)];
  }
};

int main(){
  Solution sol;
  cout << sol.wordBreak("applepenapple", {"apple", "pen"});
}
