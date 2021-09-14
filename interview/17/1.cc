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
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> res;
      for(int i = 0; i < size(nums); i++){
        int cnt = 0;
        for(int j = 0; j < size(nums); j++){
          if(j == i) continue;
          if(nums[j] < nums[i]) cnt++;
        }
        res.push_back(cnt);
      }
      return res;
    }
};
