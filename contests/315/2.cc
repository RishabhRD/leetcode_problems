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

int reverse_digit(int n) {
  int reverse = 0;
  int remainder = 0;
  while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }
  return reverse;
}

class Solution {
 public:
  int countDistinctIntegers(std::vector<int>& nums) {
    std::unordered_set<int> st;
    for (auto num : nums) {
      st.insert(num);
      st.insert(reverse_digit(num));
    }
    return st.size();
  }
};
