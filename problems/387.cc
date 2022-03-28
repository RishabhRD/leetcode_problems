#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int firstUniqChar(string const s) {
    array<int, 128> arr{ 0 };
    for (auto c : s) arr[c]++;
    for (int i = 0; i < size(s); i++)
      if (arr[s[i]] == 1) return i;
    return -1;
  }
};
