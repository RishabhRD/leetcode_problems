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
    int numIdenticalPairs(vector<int>& nums) {
      const int n = size(nums);
      int count = 0;
      for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n ; j++){
          if(nums[i] == nums[j]){
            count++;
          }
        }
      }
      return count;
    }
};
