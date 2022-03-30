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
  vector<long long> sumOfThree(long long num) {
    if (num % 3 != 0)
      return {};
    else {
      return {num / 3 - 1, num / 3, num / 3 + 1};
    }
  }
};
