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
  bool isMatch(const string &s, const string &p) {
    int i = 0, j = 0;
    int star = -1;
    int match = 0;
    const int m = size(s);
    const int n = size(p);
    while (i < m) {
      if (j < n and (s[i] == p[j] or p[j] == '?')) {
        i++;
        j++;
      } else if (j < n and p[j] == '*') {
        match = i;
        star = j;
        j++;
      } else if (star != -1) {
        j = star + 1;
        i = ++match;
      } else {
        return false;
      }
    }
    while (j < n and p[j] == '*') { j++; }
    return j == n;
  }
};

int main() {
  Solution sol;
  cout << sol.isMatch("ab", "?*") << endl;
}
