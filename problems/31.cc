#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &arr) {
    auto left = is_sorted_until(rbegin(arr), rend(arr));
    if (left != rend(arr)) {
      auto right = upper_bound(rbegin(arr), left, *left);
      iter_swap(left, right);
    }
    reverse(left.base(), end(arr));
  }
};

template <class BidirIt>
bool next_permutation(BidirIt first, BidirIt last) {
  auto r_first = std::make_reverse_iterator(last);
  auto r_last = std::make_reverse_iterator(first);
  auto left = std::is_sorted_until(r_first, r_last);
  if (left != r_last) {
    auto right = std::upper_bound(r_first, left, *left);
    iter_swap(left, right);
  }
  reverse(left.base(), last);
  return left != r_last;
}
