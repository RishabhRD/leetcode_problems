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
    int reverse(int x) {
      bool is_neg = false;
      if(x < 0){
        is_neg = true;
      }
      x = abs(x);
      long long new_num = 0;
      while(x){
        int dig = x % 10;
        new_num = new_num * 10 + dig;
        x = x / 10;
        if(new_num > INT32_MAX or new_num < INT32_MIN) return 0;
      }
      if(is_neg) {
        new_num = -new_num;
        if(new_num > INT32_MAX or new_num < INT32_MIN) return 0;
        return new_num;
      }else{
        return new_num;
      }
    }
};
