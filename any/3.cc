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
    unordered_map<char, int> count;
    int max_len = 0;
    for (int i = 0, j = 0; i < size(s); i++) {
      count[s[i]]++;
      while (count[s[i]] > 1) {
        count[s[j]]--;
        j++;
      }
      max_len = max(max_len, i - j + 1);
    }
    return max_len;
  }
};
