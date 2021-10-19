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
    int lengthOfLIS(vector<int>& nums) {
      vector<int> dp;
      for(auto n : nums){
        if(size(dp) == 0){
          dp.push_back(n);
        }else if(n > dp.back()){
          dp.push_back(n);
        }else{
          *lower_bound(begin(dp), end(dp), n) = n;
        }
      }
      return size(dp);
    }
};
