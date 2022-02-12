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
  bool isAnagram(string s, string t) {
    array<int, 128> freq{ 0 };
    for (auto c : s) freq[c]++;
    for (auto c : t) freq[c]--;
    return count(begin(freq), end(freq), 0) == 128;
  }
};
