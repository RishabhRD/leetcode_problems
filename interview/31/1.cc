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
  string convertToTitle(int n) {
    string res;
    while(n > 0){
      n--;
      char tmp = (n % 26) + 'A';
      res = tmp + res;
      n /= 26;
    }
    return res;
  }
};
