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

class Solution {
public:
  int mostWordsFound(vector<string> &sentences) {
    return transform_reduce(
      cbegin(sentences),
      cend(sentences),
      0,
      [](auto a, auto b) { return std::max(a, b); },
      [](string_view str) -> int {
        return 1 + count(begin(str), end(str), ' ');
      });
  }
};
