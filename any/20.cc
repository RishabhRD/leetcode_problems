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
    bool isValid(string s) {
      stack<char> st;
      for(auto c : s){
        if(c == '(' or c == '{' or c == '['){
          st.push(c);
        }else{
          if(empty(st)) return false;
          auto top = st.top();
          st.pop();
          if(c == ')' and top != '(') return false;
          else if(c == '}' and top != '{') return false;
          else if(c == ']' and top != '[') return false;
        }
      }
      return empty(st);
    }
};
