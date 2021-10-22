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
    int hammingWeight(uint32_t n) {
      int cnt = 0;
      while(n != 0){
        cnt += n & 1;
        n >>= 1;
      }
      return cnt;
    }
};
