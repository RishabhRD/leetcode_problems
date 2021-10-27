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
    bool isPowerOfThree(int n) {
      if(n == 0) return false;
      while(n != 1){
        if(n % 3 != 0){
          return false;
        }
        n = n / 3;
      }
      return true;
    }
};
