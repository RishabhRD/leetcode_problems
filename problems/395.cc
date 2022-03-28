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

int longest_substring(string_view const s, int k) {
  array<int, 128> arr{ 0 };
  for (auto c : s) arr[c]++;
  int idx = 0;
  while (idx < size(s) and arr[s[idx]] >= k) idx++;
  if (idx == size(s)) return size(s);
  int const left = longest_substring(s.substr(0, idx), k);
  int const right = longest_substring(s.substr(idx + 1), k);
  return max(left, right);
}

class Solution {
public:
  int longestSubstring(string s, int k) { return longest_substring(s, k); }
};
