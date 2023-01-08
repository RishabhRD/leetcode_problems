#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

class Solution {
 public:
  std::string categorizeBox(int length, int width, int height, int mass) {
    ll const volume = ll(length) * width * ll(height);
    bool bulky = false;
    bool heavy = false;
    if (length >= 1e4 || width >= 1e4 || height >= 1e4 || volume >= 1e9) {
      bulky = true;
    }
    if (mass >= 100) heavy = true;
    if (bulky and heavy) return "Both";
    if (!bulky and !heavy) return "Neither";
    if (bulky) return "Bulky";
    return "Heavy";
  }
};
