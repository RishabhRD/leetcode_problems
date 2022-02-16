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

class Solution {
public:
  int fourSumCount(vector<int> &nums1,
    vector<int> &nums2,
    vector<int> &nums3,
    vector<int> &nums4) {
    int const n = size(nums1);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) { mp[nums1[i] + nums2[j]]++; }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) { cnt += mp[-(nums3[i] + nums4[j])]; }
    }
    return cnt;
  }
};
