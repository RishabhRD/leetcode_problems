#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> mp;
    for (auto num : nums1) mp[num]++;
    vector<int> res;
    for (auto num : nums2) {
      mp[num]--;
      if (mp[num] >= 0) res.push_back(num);
    }
    return res;
  }
};
