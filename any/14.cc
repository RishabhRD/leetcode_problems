#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

string_view prefix(string_view a, string_view b) {
  auto const n = min(size(a), size(b));
  string_view s;
  for (size_t i = 0; i < n; i++) {
    if (a[i] == b[i])
      s = a.substr(0, i + 1);
    else
      break;
  }
  return s;
}

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    return accumulate(begin(strs), end(strs), strs[0], prefix);
  }
};
