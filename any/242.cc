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
      sort(begin(s), end(s));
      sort(begin(t), end(t));
      return s == t;
    }
};
