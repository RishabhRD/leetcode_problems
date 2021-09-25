#include <unordered_map>
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
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> mp;
    for (int i = 0; i < size(nums1); i++) { mp[nums1[i]] = i; }
    stack<int> st;
    vector<int> greater_vec(size(nums1));

    for (int i = size(nums2) - 1; i >= 0; i--) {
      while (not empty(st) and st.top() < nums2[i]) { st.pop(); }
      if (mp.find(nums2[i]) != mp.end()) {
        if (empty(st))
          greater_vec[mp[nums2[i]]] = -1;
        else
          greater_vec[mp[nums2[i]]] = st.top();
      }
      st.push(nums2[i]);
    }
    return greater_vec;
  }
};
