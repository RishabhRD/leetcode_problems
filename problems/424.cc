#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

auto get_freq(string_view str) {
  array<int, 128> freq{0};
  for (auto c : str) {
    ++freq[c];
  }
  return freq;
}

auto get_most_frequent_char(array<int, 128> freq) {
  int max_val = 0;
  char most_freq_char = '0';
  for (auto c = 'A'; c <= 'Z'; ++c) {
    if (freq[c] > max_val) {
      most_freq_char = c;
      max_val = freq[c];
    }
  }
  return most_freq_char;
}

class Solution {
 public:
  int characterReplacement(string s, int k) {
    auto const freq_c = get_most_frequent_char(get_freq(s));
    auto const n = size(s);
    size_t i{};
    size_t max_len{};
    int unmatched_cnt = 0;
    for (size_t j{}; j < n; ++j) {
      if (s[j] != freq_c) ++unmatched_cnt;
      while (unmatched_cnt > k) {
        if (s[i] != freq_c) --unmatched_cnt;
        ++i;
      }
      max_len = max(max_len, j - i + 1);
    }
    return max_len;
  }
};
