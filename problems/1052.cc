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

int if_else(bool cond, int satisfies, int not_satisfies) {
  return cond ? satisfies : not_satisfies;
}

int calc_num_customer_satisfy(int customers, int grumpy) {
  return if_else(!grumpy, customers, 0);
}

int calc_num_customer_unsatisfy(int customers, int grumpy) {
  return if_else(grumpy, customers, 0);
}

auto make_unsatisfied(std::vector<int> const& customers,
                      std::vector<int> const& grumpy) {
  std::vector unsatisfied(std::size(customers), 0);
  std::transform(std::begin(customers), std::end(customers), std::begin(grumpy),
                 std::begin(unsatisfied), calc_num_customer_unsatisfy);
  return unsatisfied;
}

auto max_window_sum(std::vector<int> const& nums, int k) {
  int low = 0;
  int cur_sum = 0;
  int max_sum = 0;
  for (int high = 0; high < std::size(nums); ++high) {
    cur_sum += nums[high];
    if (high - low + 1 > k) {
      cur_sum -= nums[low];
      ++low;
    }
    if (high - low + 1 == k) {
      max_sum = std::max(max_sum, cur_sum);
    }
  }
  return max_sum;
}

class Solution {
 public:
  int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy,
                   int minutes) {
    auto const unsatisfied = make_unsatisfied(customers, grumpy);
    auto const satisfied_customers = std::transform_reduce(
        std::begin(customers), std::end(customers), std::begin(grumpy), 0,
        std::plus{}, calc_num_customer_satisfy);
    return max_window_sum(unsatisfied, minutes) + satisfied_customers;
  }
};
