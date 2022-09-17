#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool checkInclusion(std::string s1, std::string s2) {
    std::array<int, 128> arr1{0};
    for (auto c : s1) ++arr1[c];

    std::array<int, 128> arr2{0};

    int low = 0;
    for (int high = 0; high < std::size(s2); ++high) {
      ++arr2[s2[high]];
      if (high - low + 1 > std::size(s1)) {
        --arr2[s2[low]];
        ++low;
      }
      if (high - low + 1 == std::size(s1)) {
        if (arr1 == arr2) return true;
      }
    }
    return false;
  }
};
