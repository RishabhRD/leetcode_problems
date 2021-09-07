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
    uint32_t reverseBits(uint32_t n) {
      if(n == 0) return 0;
      int result = 0;
      for(int i = 0; i < 32; i++){
        result <<= 1;
        if(n & 1) result++;
        n >>= 1;
      }
      return result;
    }
};
