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
    string reverseParentheses(string s) {
      string res = "";
      stack<string> st;
      for(auto c : s){
        if(c == '('){
          st.push("");
        }else if(c == ')'){
          auto top = st.top();
          reverse(begin(top), end(top));
          st.pop();
          if(empty(st)){
            res += top;
          }else{
            st.top() += top;
          }
        }else{
          if(empty(st)){
            res += c;
          }else{
            st.top() += c;
          }
        }
      }
      return res;
    }
};
