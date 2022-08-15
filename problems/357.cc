#include <algorithm>
#include <numeric>
#include <vector>

auto make_partial_sum() {
  std::vector partial_sum{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::partial_sum(std::cbegin(partial_sum), std::cend(partial_sum),
                   std::begin(partial_sum), std::multiplies{});
  return partial_sum;
}

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    auto const cont_mult = make_partial_sum();
    auto const first_n_sum =
        std::accumulate(std::cbegin(cont_mult), std::cbegin(cont_mult) + n, 0);
    return first_n_sum - (first_n_sum / 10) + 1;
  }
};
