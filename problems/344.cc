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
    void reverseString(vector<char>& s) {
      size_t begin = 0;
      size_t end = size(s) - 1;
      while(begin < end){
        swap(s[begin++], s[end--]);
      }
    }
};
