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

int subarray_sum_2(std::vector<int> const& nums, int firstLen, int secondLen) {
  auto const n = std::size(nums);
  if (firstLen + secondLen > n) return 0;
  auto first_begin = std::cbegin(nums);
  auto first_end = std::cbegin(nums) + firstLen;
  auto second_end = std::cbegin(nums) + firstLen + secondLen;
  auto cur_first_sum = std::reduce(first_begin, first_end, 0);
  auto cur_second_sum = std::reduce(first_end, second_end, 0);
  auto max_first_sum = cur_first_sum;
  auto res = cur_first_sum + cur_second_sum;
  while (second_end != std::cend(nums)) {
    cur_first_sum -= *first_begin;
    cur_first_sum += *first_end;
    max_first_sum = std::max(max_first_sum, cur_first_sum);
    cur_second_sum -= *first_end;
    cur_second_sum += *second_end;
    res = std::max(res, max_first_sum + cur_second_sum);
    ++first_begin;
    ++first_end;
    ++second_end;
  }
  return res;
}

class Solution {
 public:
  int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen) {
    return std::max(subarray_sum_2(nums, firstLen, secondLen),
                    subarray_sum_2(nums, secondLen, firstLen));
  }
};
