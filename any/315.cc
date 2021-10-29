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

struct element {
  int ele;
  int idx;
};

void count_invert(vector<element> &nums,
  vector<int> &result,
  int low,
  int high) {
  if (low == high) return;
  int mid = (low + high) / 2;
  count_invert(nums, result, low, mid);
  count_invert(nums, result, mid + 1, high);
  vector<element> first(begin(nums) + low, begin(nums) + mid + 1);
  vector<element> second(begin(nums) + mid + 1, begin(nums) + high + 1);
  int first_idx = 0;
  int second_idx = 0;
  int fill_idx = low;
  int num_inverted = 0;
  while (first_idx < size(first) and second_idx < size(second)) {
    if (first[first_idx].ele > second[second_idx].ele) {
      num_inverted++;
      nums[fill_idx++] = second[second_idx++];
    } else {
      result[first[first_idx].idx] += num_inverted;
      nums[fill_idx++] = first[first_idx++];
    }
  }
  while (first_idx < size(first)) {
    result[first[first_idx].idx] += num_inverted;
    nums[fill_idx++] = first[first_idx++];
  }
  while (second_idx < size(second)) {
    num_inverted++;
    nums[fill_idx++] = second[second_idx++];
  }
}

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    vector<element> vec;
    for (int i = 0; i < size(nums); i++) { vec.push_back({ nums[i], i }); }
    vector<int> result(size(nums));
    count_invert(vec, result, 0, size(nums) - 1);
    return result;
  }
};
