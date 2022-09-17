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

auto make_max_or(std::vector<int> const& vec) {
  std::vector<int> res(std::size(vec));
  std::partial_sum(std::rbegin(vec), std::rend(vec), std::rbegin(res),
                   [](auto a, auto b) { return a | b; });
  return res;
}

auto value_of(std::array<int, 32> const& contrib) {
  std::bitset<32> bs{};
  for (int i = 0; i < 32; ++i) {
    if (contrib[i] > 0) bs[i] = true;
  }
  return bs.to_ulong();
}

auto add_contrib(std::array<int, 32>& contrib, int ele) {
  std::bitset<32> bs(ele);
  for (int i = 0; i < 32; ++i) {
    if (bs[i]) {
      ++contrib[i];
    }
  }
}

auto remove_contrib(std::array<int, 32>& contrib, int ele) {
  std::bitset<32> bs(ele);
  for (int i = 0; i < 32; ++i) {
    if (bs[i]) {
      --contrib[i];
    }
  }
}

class Solution {
 public:
  std::vector<int> smallestSubarrays(std::vector<int>& nums) {
    auto const max_or = make_max_or(nums);
    int low = 0;
    std::array<int, 32> contrib = {0};
    std::vector<int> ans(std::size(nums));
    for (int high = 0; high < std::size(nums); ++high) {
      add_contrib(contrib, nums[high]);
      while (low <= high and value_of(contrib) >= max_or[low]) {
        ans[low] = high - low + 1;
        remove_contrib(contrib, nums[low]);
        ++low;
      }
    }
    return ans;
  }
};
