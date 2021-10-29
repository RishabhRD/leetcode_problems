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
    int trailingZeroes(int n) {
      int res = 0;
      for(long long i = 5; n / i > 0; i *= 5){
        res += (n / i);
      }
      return res;
    }
};
