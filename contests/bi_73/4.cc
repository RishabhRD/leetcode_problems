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
  int minMovesToMakePalindrome(string s) {
    int min_swap = 0;
    auto left = begin(s);
    auto right = rbegin(s);
    while (distance(left, right.base()) - 1 > 0) {
      if (*left != *right) {
        auto req_ele_itr = find(left, right.base(), *right);
        auto const ele_dist = distance(left, req_ele_itr);
        if (distance(req_ele_itr, right.base()) == 1) {
          --left;  // Don't want to increase left
          min_swap += ele_dist / 2;
        } else {
          min_swap += ele_dist;
          rotate(left, req_ele_itr, req_ele_itr + 1);
        }
      }
      ++left;
      ++right;
    }
    return min_swap;
  }
};

int main() {
  Solution sol;
  sol.minMovesToMakePalindrome("scpcyxprxxsjyjrww");
}
