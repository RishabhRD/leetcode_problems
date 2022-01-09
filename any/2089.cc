#include <optional>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

auto first_index_of(vector<int> &nums, int target) {
  optional<int> first_occurence_index;
  int low = 0;
  int high = size(nums) - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      first_occurence_index = mid;
      high = mid - 1;
    } else if (nums[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return first_occurence_index;
}

auto last_index_of(vector<int> &nums, int target) {
  optional<int> last_occurence_index;
  int low = 0;
  int high = size(nums) - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      last_occurence_index = mid;
      low = mid + 1;
    } else if (nums[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return last_occurence_index;
}

class Solution {
public:
  vector<int> targetIndices(vector<int> &nums, int target) {
    sort(begin(nums), end(nums));
    auto first_index = first_index_of(nums, target);
    auto last_index = last_index_of(nums, target);
    if (!first_index.has_value()) {
      return {};
    } else {
      vector<int> res;
      for (int i = *first_index; i <= *last_index; i++) { res.push_back(i); }
      return res;
    }
  }
};
