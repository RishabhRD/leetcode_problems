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

using ll = long long;

void merge(ll low, ll mid, ll high, std::vector<std::pair<ll, ll>>& nums,
           std::vector<int>& res) {
  ll j = mid;
  for (ll i = low; i < mid; ++i) {
    while (j < high && nums[i] > nums[j]) {
      ++j;
    }
    res[nums[i].second] += j - mid;
  }
  std::sort(std::begin(nums) + low, std::begin(nums) + high);
}

void merge_sort(ll low, ll high, std::vector<std::pair<ll, ll>>& nums,
                std::vector<int>& res) {
  if (high - low <= 1) return;

  auto const mid = (low + high) / 2;
  merge_sort(low, mid, nums, res);
  merge_sort(mid, high, nums, res);
  merge(low, mid, high, nums, res);
}

class Solution {
 public:
  std::vector<int> countSmaller(std::vector<int>& nums) {
    ll const n = nums.size();
    std::vector<std::pair<ll, ll>> arr;
    for (ll i = 0; i < n; ++i) {
      arr.push_back({nums[i], i});
    }
    std::vector res(n, 0);
    merge_sort(0, n, arr, res);
    return res;
  }
};
