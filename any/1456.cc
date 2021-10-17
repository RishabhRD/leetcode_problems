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

bool is_vowel(const char c) {
  return c == 'a' or c == 'e' or c == 'o' or c == 'i' or c == 'u';
}

class Solution {
public:
  int maxVowels(string s, int k) {
    int num_vowels = count_if(cbegin(s), cbegin(s) + k, &is_vowel);
    int max_vowels = num_vowels;
    const int n = size(s);
    for(int i = 0; i < n - k; i++){
      num_vowels -= is_vowel(s[i]);
      num_vowels += is_vowel(s[i + k]);
      max_vowels = max(max_vowels, num_vowels);
    }
    return max_vowels;
  }
};
