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
  int numberOfSubstrings(string s) {
    int num_arr[3]{0};
    auto num = [&](char c) -> int&{
      return num_arr[c - 'a'];
    };

    int res = 0;
    int low = 0;
    for(char c : s){
      num(c)++;
      while(num('a') and num('b') and num('c')){
        num(s[low++])--;
      }
      res += low;
    }
    return res;
  }
};
