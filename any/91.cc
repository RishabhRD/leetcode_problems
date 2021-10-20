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
      const auto n = size(s);
      int dp1 = 1, dp2 = 0, dp = 0;
      for(int i = n - 1; i >= 0; i--){
        if(s[i] != '0'){
          dp += dp1;
        }
        if(i + 1 < n and (s[i] == '1' or s[i] == '2' and s[i + 1] <= '6')){
          dp += dp2;
        }
        dp2 = dp1;
        dp1 = dp;
        dp = 0;
      }
      return dp1;
    }
};
