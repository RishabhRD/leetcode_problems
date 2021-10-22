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
  void sortColors(vector<int> &nums) {
    int arr[3]{0};
    for(int i = 0; i < size(nums); i++){
      arr[nums[i]]++;
    }
    int cur_idx = 0;
    for(int i = 0; i < 3; i++){
      while(arr[i]--){
        nums[cur_idx++] = i;
      }
    }
  }
};
