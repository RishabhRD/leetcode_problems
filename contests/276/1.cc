#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1{begin(nums1), end(nums1)};
    unordered_set<int> s2{begin(nums2), end(nums2)};
    vector<int> res1;
    for (auto e : s1) {
      if (s2.find(e) == s2.end()) res1.push_back(e);
    }
    vector<int> res2;
    for (auto e : s2) {
      if (s1.find(e) == s1.end()) res2.push_back(e);
    }
    return {std::move(res1), std::move(res2)};
  }
};
