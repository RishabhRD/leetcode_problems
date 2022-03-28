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
    int strStr(string haystack, string needle) {
      if(empty(needle)) return 0;
      int idx = haystack.find(needle);
      if(idx == string::npos){
        return -1;
      }
      return idx;
    }
};
