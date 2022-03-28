#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

auto rotation_point(vector<int> const &vec) {
  int low = 0;
  int high = size(vec) - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (vec[mid] > vec[high])
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}

class Solution {
public:
  int search(vector<int> const &nums, int target) {
    int const n = size(nums);
    int const num_rotated = rotation_point(nums);
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int const mid = (low + high) / 2;
      int const real_mid = (mid + num_rotated) % n;
      if (nums[real_mid] == target)
        return real_mid;
      else if (nums[real_mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
  cout << sol.search(arr, 0) << endl;
}
