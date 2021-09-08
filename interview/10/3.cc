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

bool is_digit(char c) {
  int num = c - '0';
  return num >= 0 and num <= 9;
}

int get_digit(char c){
  return c - '0';
}

bool is_symbol(char c){
  return c == '/' or c == '*' or c == '+' or c == '-';
}

void do_pending_operations(char sym, int num, stack<int>& s){
  if(sym == '+'){
    s.push(num);
  }else if(sym == '-'){
    s.push(-num);
  }else if(sym == '*'){
    int top = s.top();
    s.pop();
    s.push(top * num);
  }else{
    int top = s.top();
    s.pop();
    s.push(top / num);
  }
}

class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    char sign = '+';
    int num = 0;
    for (auto c : s) {
      if (is_digit(c)) {
        num = num * 10 + get_digit(c);
      }else if(is_symbol(c)){
        do_pending_operations(sign, num, st);
        num = 0;
        sign = c;
      }
    }
    do_pending_operations(sign, num, st);
    int ans = 0;
    while(not empty(st)){
      int top = st.top();
      st.pop();
      ans += top;
    }
    return ans;
  }
};

int main(){
  Solution sol;
  cout << sol.calculate("1+1-1") << endl;
}
