#include <unordered_set>
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
    int maximumUniqueSubarray(vector<int>& nums) {
      int i = 0;
      int j = 0;
      const int n = size(nums);
      unordered_set<int> st;
      auto contains = [&](int num){
        return st.find(num) != st.end();
      };
      int sum = 0;
      int ans = 0;
      while(i < n and j < n){
        if(contains(nums[j])){
          sum -= nums[i];
          st.erase(nums[i++]);
        }else{
          sum += nums[j];
          st.insert(nums[j++]);
          ans = max(sum, ans);
        }
      }
      return ans;
    }
};
