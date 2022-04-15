#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSubstrings(string s) {
    array<int, 3> cnt{0};
    auto num = [&cnt](auto c) -> int& { return cnt[c - 'a']; };
    int const n = size(s);
    int i{};
    int res{};
    for (int j{}; j < n; ++j) {
      ++num(s[j]);
      while (num('a') and num('b') and num('c')) {
        --num(s[i]);
        ++i;
      }
      res += i;
    }
    return res;
  }
};
