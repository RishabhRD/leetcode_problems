#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <stack>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
      int res = 0;
      int l = 0;
      int n = size(s);
      for(int i = 0; i < n; i++){
        if(s[i] == '(') l++;
        else l--;
        if(s[i] == ')' and s[i - 1] == '('){
          res += 1 << l;
        }
      }
      return res;
    }
};
