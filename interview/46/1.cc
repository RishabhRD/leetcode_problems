#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
  string modifyString(string s) {
    int const n = size(s);
    for (int i = 0; i < size(s); i++) {
      if (s[i] == '?') {
        for (s[i] = 'a'; s[i] <= 'c'; s[i]++) {
          if ((i == 0 || s[i - 1] != s[i]) && (i == n - 1 || s[i] != s[i + 1]))
            break;
        }
      }
    }
    return s;
  }
};
