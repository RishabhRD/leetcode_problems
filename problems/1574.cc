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

class Solution {
 public:
  int findLengthOfShortestSubarray(std::vector<int>& arr) {
    int const n = std::size(arr);
    int const left = std::is_sorted_until(std::cbegin(arr), std::cend(arr)) -
                     std::cbegin(arr) - 1;
    if (left == n - 1) return 0;
    int right = n - 1;
    while (right > left and arr[right - 1] <= arr[right]) --right;
    int ans = std::min(n - left - 1, right);
    int j = right;
    int i = 0;
    while (i <= left and j < n) {
      if (arr[i] <= arr[j]) {
        ans = std::min(ans, j - i - 1);
        ++i;
      } else {
        ++j;
      }
    }
    return ans;
  }
};
