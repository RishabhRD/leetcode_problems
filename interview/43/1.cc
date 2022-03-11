#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

string_view prefix(string_view str1, string_view str2) {
  int const m = size(str1);
  int const n = size(str2);
  int len = 0;
  for (int i = 0; i < min(m, n); i++) {
    if (str1[i] == str2[i])
      len++;
    else
      break;
  }
  return str1.substr(0, len);
}

class Solution {
public:
  string longestCommonPrefix(vector<string> const &strs) {
    auto first = begin(strs);
    string_view init_ele = *first;
    return string{ accumulate(next(first), end(strs), init_ele, prefix) };
  }
};
