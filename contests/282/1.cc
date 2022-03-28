#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    return count_if(begin(words), end(words), [&pref](string_view str) {
      if (size(pref) > size(str)) return false;
      return std::equal(begin(pref), end(pref), begin(str));
    });
  }
};
