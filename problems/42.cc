#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

namespace ufo {
template <typename T = void>
struct min {
  constexpr T const& operator()(T const& a, T const& b) const noexcept {
    return std::min(a, b);
  }
};

template <>
struct min<void> {
  template <typename T1, typename T2>
  constexpr auto operator()(T1 const& a, T2 const& b) const noexcept
      -> decltype(std::min(a, b)) {
    return std::min(a, b);
  }
};

template <typename T = void>
struct max {
  constexpr T const& operator()(T const& a, T const& b) const noexcept {
    return std::max(a, b);
  }
};

template <>
struct max<void> {
  template <typename T1, typename T2>
  constexpr auto operator()(T1 const& a, T2 const& b) const noexcept
      -> decltype(std::max(a, b)) {
    return std::max(a, b);
  }
};

template <typename T = void>
struct abs_diff {
  constexpr T const& operator()(T const& a, T const& b) const noexcept {
    return std::abs(a - b);
  }
};

template <>
struct abs_diff<void> {
  template <typename T1, typename T2>
  constexpr auto operator()(T1 const& a, T2 const& b) const noexcept
      -> decltype(std::abs(a - b)) {
    return std::abs(a - b);
  }
};

template <typename T>
class plus {
  T val;

 public:
  explicit plus(T v) : val(v) {}

  constexpr auto operator()(T const& a) const noexcept { return val + a; };
};
}  // namespace ufo

class Solution {
 public:
  int trap(vector<int>& height) {
    constexpr auto max = [](auto a, auto b) { return std::max(a, b); };
    vector<int> max_heights(size(height), 0);
    auto max_itr = max_element(cbegin(height), cend(height));
    inclusive_scan(cbegin(height), max_itr, begin(max_heights), max);
    inclusive_scan(crbegin(height), make_reverse_iterator(max_itr),
                   rbegin(max_heights), max);
    return transform_reduce(cbegin(max_heights), cend(max_heights),
                            cbegin(height), 0, std::plus<>{}, std::minus<>{});
  }
};

// C++23 Algorithm
int trap(vector<int>& height) {
  auto max_itr = max_element(cbegin(height), cend(height));
  auto left_max_heights =
      views::inclusive_scan(ranges::subrange(cbegin(height), max_itr));
  auto right_max_heights = views::inclusive_scan(
      ranges::subrange(crbegin(height), make_reverse_iterator(max_itr)));
  auto const left_sum =  views::zip(left_max_heights, height)
                         | views::transform(std::minus<>{})
                         | ranges::fold(0);
  auto const right_sum = views::zip(right_max_heights, height)
                         | views::transform(std::minus<>{})
                         | ranges::fold(0);
  return left_sum + right_sum;
}
