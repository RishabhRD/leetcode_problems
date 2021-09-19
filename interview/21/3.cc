#include <list>
#include <queue>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      const int n = size(nums);
      vector<int> res;
      list<pair<int, int>> st;
      auto push = [&](int i, int ele){
        while(not empty(st)){
          auto [ind, top] = st.back();
          if(top <= ele){
            st.pop_back();
          }else{
            break;
          }
        }
        st.emplace_back(i, ele);
      };
      for(int i = 0; i < k; i++){
        push(i, nums[i]);
      }
      for(int i = 0; i <= n - k; i++){
        auto [ind, top] = st.front();
        res.push_back(top);
        if(ind == i){
          st.pop_front();
        }
        if(i + k < n)
          push(i + k, nums[i + k]);
      }
      return res;
    }
};
