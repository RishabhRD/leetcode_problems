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
    set<int> s1{begin(nums1), end(nums1)};
    set<int> s2{begin(nums2), end(nums2)};
    vector<int> res1;
    set_difference(begin(s1), end(s1), begin(s2), end(s2), back_inserter(res1));
    vector<int> res2;
    set_difference(begin(s2), end(s2), begin(s1), end(s1), back_inserter(res2));
    return {std::move(res1), std::move(res2)};
  }
};
