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

bool is_digit(char c){
  return c - '0' >= 0 and c - '0' <= 9;
}

int digit(char c){
  return c - '0';
}

class Solution {
public:
  int myAtoi(string s) {
    int i = 0;
    const int n = size(s);

    // handle leading whitespace
    while(i < n){
      if(s[i] == ' '){
        i++;
      }else{
        break;
      }
    }

    // handle +ve and -ve
    bool neg = false;
    if(i < n){
      if(s[i] == '-') neg = true;
      if(s[i] == '-' or s[i] == '+') i++;
    }

    long long res = 0;
    bool unbounded = false;
    while(i < n and is_digit(s[i])){
      res = res * 10 + digit(s[i]);
      if(res > INT32_MAX){
        unbounded = true;
        break;
      }
      i++;
    }

    if(neg){
      res = -res;
    }

    if(res < INT32_MIN){
      unbounded = true;
    }
    if(unbounded){
      if(res > 0) return INT32_MAX;
      else return INT32_MIN;
    }
    return res;
  }
};
