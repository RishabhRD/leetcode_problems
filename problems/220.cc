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
  bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    std::unordered_map<int, int> buckets;
    int low = 0;
    for (int high = 0; high < std::size(nums); ++high) {
      if (high - low > indexDiff) {
        int const low_bucket = nums[low] / (valueDiff + 1);
        buckets.erase(low_bucket);
        ++low;
      }
      int bucket = nums[high] / (valueDiff + 1);
      if (nums[high] < 0) --bucket;
      if (buckets.find(bucket) != buckets.end()) return true;
      if (buckets.find(bucket + 1) != buckets.end() and
          buckets[bucket + 1] - nums[high] <= valueDiff)
        return true;
      if (buckets.find(bucket - 1) != buckets.end() and
          nums[high] - buckets[bucket - 1] <= valueDiff)
        return true;
      buckets[bucket] = nums[high];
    }
    return false;
  }
};
