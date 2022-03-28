#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

auto first_idx(vector<int> const &nums, int const target) {
  int idx = -1;
  int low = 0;
  int high = size(nums) - 1;
  while (low <= high) {
    int const mid = (low + high) / 2;
    if (nums[mid] >= target)
      high = mid - 1;
    else
      low = mid + 1;
    if (nums[mid] == target) idx = mid;
  }
  return idx;
}

auto last_idx(vector<int> const &nums, int const target) {
  int idx = -1;
  int low = 0;
  int high = size(nums) - 1;
  while (low <= high) {
    int const mid = (low + high + 1) / 2;
    if (nums[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
    if (nums[mid] == target) idx = mid;
  }
  return idx;
}

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    return vector({ first_idx(nums, target), last_idx(nums, target) });
  }
};

int main() {
  vector<int> vec{ 1, 2, 3, 4, 4, 4, 5, 6, 7, 7, 7 };
  cout << first_idx(vec, 11) << endl;
  cout << last_idx(vec, 11) << endl;
}
