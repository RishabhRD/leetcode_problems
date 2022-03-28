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
  string convert(string s, int numRows) {
    vector row_str(numRows, ""s);
    int i = 0;
    const int n = size(s);
    while (i < n) {
      for (int j = 0; j < numRows and i < n; j++) row_str[j] += s[i++];
      for (int j = numRows - 2; j > 0 and i < n; j--) row_str[j] += s[i++];
    }
    return accumulate(begin(row_str), end(row_str), ""s);
  }
};
