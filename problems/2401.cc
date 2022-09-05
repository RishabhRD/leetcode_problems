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
  int longestNiceSubarray(std::vector<int>& nums) {
    std::array<int, 32> num_bits{0};
    auto is_fine = [&num_bits]() {
      return std::all_of(std::cbegin(num_bits), std::cend(num_bits),
                         [](auto ele) { return ele == 0 || ele == 1; });
    };
    auto add_ele = [&num_bits](int ele) {
      std::bitset<32> bs(ele);
      for (int i = 0; i < 32; ++i) {
        if (bs.test(i)) {
          ++num_bits[i];
        }
      }
    };
    auto remove_ele = [&num_bits](int ele) {
      std::bitset<32> bs(ele);
      for (int i = 0; i < 32; ++i) {
        if (bs.test(i)) {
          --num_bits[i];
        }
      }
    };

    int ans = 0;
    int low = 0;
    auto const n = std::size(nums);
    for (int high = 0; high < n; ++high) {
      add_ele(nums[high]);
      while (!is_fine()) {
        remove_ele(nums[low]);
        ++low;
      }
      ans = std::max(ans, high - low + 1);
    }
    return ans;
  }
};
