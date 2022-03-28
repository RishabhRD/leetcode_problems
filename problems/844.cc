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

auto type(string_view s) {
  vector<char> vec;
  for (auto c : s) {
    if (c == '#') {
      if (not empty(vec)) vec.pop_back();
    } else
      vec.push_back(c);
  }
  return vec;
}

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    auto s1 = type(s);
    auto s2 = type(t);
    return equal(begin(s1), end(s1), begin(s2), end(s2));
  }
};
