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

class MountainArray {
  vector<int> vec;

public:
  MountainArray(vector<int> vec) : vec(std::move(vec)) {}
  int get(int index) { return vec[index]; }
  int length() { return size(vec); }
};

int find_mountain(MountainArray &mountainArr, vector<int> &dp) {
  int low = 0;
  int high = mountainArr.length() - 1;
  int ans = 0;
  auto at = [&](int i) {
    if (i < 0) return -1;
    if (i >= mountainArr.length()) return INT32_MAX;
    if (dp[i] >= 0) return dp[i];
    auto ans = mountainArr.get(i);
    dp[i] = ans;
    return ans;
  };
  while (low <= high) {
    int mid = (low + high) / 2;
    if (at(mid) > at(mid - 1) and at(mid) > at(mid + 1)) {
      ans = mid;
      break;
    } else if (at(mid) > at(mid - 1) and at(mid + 1) > at(mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int b_search_inc(int target,
  int low,
  int high,
  MountainArray &mountainArr,
  vector<int> &dp) {
  auto at = [&](int i) {
    if (i < 0) return -1;
    if (i >= mountainArr.length()) return INT32_MAX;
    if (dp[i] >= 0) return dp[i];
    auto ans = mountainArr.get(i);
    dp[i] = ans;
    return ans;
  };
  while (low <= high) {
    int mid = (low + high) / 2;
    if (at(mid) == target) {
      return mid;
    } else {
      if (at(mid) > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }
  return -1;
}

int b_search_dec(int target,
  int low,
  int high,
  MountainArray &mountainArr,
  vector<int> &dp) {
  auto at = [&](int i) {
    if (i < 0) return -1;
    if (i >= mountainArr.length()) return INT32_MAX;
    if (dp[i] >= 0) return dp[i];
    auto ans = mountainArr.get(i);
    dp[i] = ans;
    return ans;
  };
  while (low <= high) {
    int mid = (low + high) / 2;
    if (at(mid) == target)
      return mid;
    else {
      if (at(mid) > target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return -1;
}


class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    vector<int> dp(mountainArr.length(), -1);
    int ind = find_mountain(mountainArr, dp);
    int first_search = b_search_inc(target, 0, ind, mountainArr, dp);
    if (first_search >= 0) return first_search;
    return b_search_dec(
      target, ind + 1, mountainArr.length() - 1, mountainArr, dp);
  }
};

int main() {
  MountainArray mnt({ 1, 2, 3, 4, 5, 3, 1 });
  Solution sol;
  cout << sol.findInMountainArray(3, mnt) << endl;
}
