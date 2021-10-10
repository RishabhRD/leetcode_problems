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
    int mctFromLeafValues(vector<int>& arr) {
      int res = 0;
      vector<int> stack = {INT32_MAX};
      for(auto n : arr){
        while(stack.back() <= n){
          int top = stack.back();
          stack.pop_back();
          res += top * min(stack.back(), n);
        }
        stack.push_back(n);
      }
      int n = size(stack);
      for(int i = 2; i < n; i++){
        res += stack[i] * stack[i - 1];
      }
      return res;
    }
};
