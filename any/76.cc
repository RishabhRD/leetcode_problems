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
  string minWindow(string s, string t) {
    vector<int> count(128);
    for (auto c : t) count[c]++;
    int counter = size(t);
    const int n = size(s);
    int i = 0;
    int min_len = INT32_MAX;
    int head = 0;
    for (int j = 0; j < n; j++) {
      if (count[s[j]] > 0) counter--;
      count[s[j]]--;
      while (counter == 0) {
        if (j - i + 1 < min_len) {
          min_len = j - i + 1;
          head = i;
        }
        count[s[i]]++;
        if (count[s[i]] > 0) { counter++; }
        i++;
      }
    }
    return min_len == INT32_MAX ? "" : s.substr(head, min_len);
  }
};
