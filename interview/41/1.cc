#include <bitset>
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
  constexpr bool isPowerOfFour(int n) {
    while (n != 1 and n != 0) {
      if (n % 4 != 0) return false;
      n = n / 4;
    }
    return n == 1;
  }
};

int main() {
  Solution sol;
  sol.isPowerOfFour(16);
}
