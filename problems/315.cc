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

using Iter = vector<pair<int, int>>::iterator;

auto get_mid(Iter low, Iter high) {
  int const n = distance(low, high);
  auto mid = low;
  advance(mid, n / 2);
  return mid;
}

void sort_count(Iter low, Iter high, vector<int> &count) {
  if (distance(low, high) <= 1) return;
  Iter mid = get_mid(low, high);

  auto left = low;
  auto right = mid;

  sort_count(low, mid, count);
  sort_count(mid, high, count);

  for (auto i = left, j = mid; i < mid; i++) {
    while (j < high && i->first > j->first) { ++j; }
    count[i->second] += distance(mid, j);
  }

  inplace_merge(low, mid, high);
}

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int const n = size(nums);
    vector count(n, 0);
    vector<pair<int, int>> zipped_vec;
    for (int i = 0; i < n; i++) zipped_vec.emplace_back(nums[i], i);
    sort_count(begin(zipped_vec), end(zipped_vec), count);
    return count;
  }
};
