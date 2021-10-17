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
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    unordered_map<char, int> count;
    const int n = size(s);
    int i = 0;
    for (int j = 0; j < n; j++) {
      count[s[j]]++;
      while (count[s[j]] > 1) { count[s[i++]]--; }
      max_len = max(max_len, j - i + 1);
    }
    return max_len;
  }
};
