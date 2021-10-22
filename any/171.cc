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
    int titleToNumber(string columnTitle) {
      int sum = 0;
      for(auto c : columnTitle){
        sum *= 26;
        sum += c - 'A' + 1;
      }
      return sum;
    }
};
