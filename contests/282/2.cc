#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSteps(string s, string t) {
    array<int, 128> freq_s{0};
    array<int, 128> freq_t{0};
    for (auto c : s) ++freq_s[c];
    for (auto c : t) ++freq_t[c];
    return transform_reduce(begin(freq_s), end(freq_s), begin(freq_t), 0,
                            std::plus<>{},
                            [](auto a, auto b) { return std::abs(a - b); });
  }
};
