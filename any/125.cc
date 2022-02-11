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
  bool isPalindrome(string s) {
    int low = 0;
    int high = size(s) - 1;
    while (low < high) {
      if (!isalnum(s[low]))
        low++;
      else if (!isalnum(s[high]))
        high--;
      else {
        if (tolower(s[low++]) != tolower(s[high--])) return false;
      }
    }
    return true;
  }
};
