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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int> const& nums) {
    if (nums.size() == 0) return {};
    std::vector<std::string> res;
    int low = 0;
    for (int high = 1; high < std::size(nums); ++high) {
      if (long(nums[high]) - long(nums[high - 1]) != 1) {
        if (high - 1 == low) {
          res.push_back(std::to_string(nums[high - 1]));
        } else {
          res.push_back(std::to_string(nums[low]) + "->" +
                        std::to_string(nums[high - 1]));
        }
        low = high;
      }
    }
    if (low == std::size(nums) - 1) {
      res.push_back(std::to_string(nums[low]));
    } else {
      res.push_back(std::to_string(nums[low]) + "->" +
                    std::to_string(nums[std::size(nums) - 1]));
    }
    return res;
  }
};
