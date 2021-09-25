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
    string removeOuterParentheses(string s) {
      string res;
      int cnt = 0;
      for(auto c : s){
        if(c == '('){
          if(cnt != 0){
            res += c;
          }
          cnt++;
        }else{
          cnt--;
          if(cnt != 0){
            res += c;
          }
        }
      }
      return res;
    }
};
