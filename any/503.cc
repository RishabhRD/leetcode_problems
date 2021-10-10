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
    vector<int> nextGreaterElements(vector<int>& nums) {
      vector<int> stack;
      const int n = size(nums);
      vector<int> res(n, -1);
      for(int i = 0; i < n * 2; i++){
        while(size(stack) and nums[stack.back()] < nums[i % n]){
          res[stack.back()] = nums[i % n];
          stack.pop_back();
        }
        stack.push_back(i % n);
      }
      return res;
    }
};
