#include <map>
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
  int romanToInt(string s) {
    map<char, int> mp{
      { 'I', 1 },
      { 'V', 5 },
      { 'X', 10 },
      { 'L', 50 },
      { 'C', 100 },
      { 'D', 500 },
      { 'M', 1000 },
    };

    int num = 0;
    for (int i = 0; i < size(s) - 1; i++) {
      char c = s[i];
      char next = s[i + 1];
      if (mp[c] < mp[next])
        num -= mp[c];
      else
        num += mp[c];
    }
    num += mp[s[size(s) - 1]];
    return num;
  }
};
