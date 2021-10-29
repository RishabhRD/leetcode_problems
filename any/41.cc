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

void print(vector<int>& vec){
  for(int num : vec){
    cout << num << " ";
  }
  cout << endl;
}

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    const int n = size(nums);
    for(int& num : nums){
      if(num <= 0 or num > n){
        num = n + 1;
      }
    }
    for(int num : nums){
      num = abs(num);
      if(num == n + 1) continue;
      num--;
      if(nums[num] > 0) nums[num] = -nums[num];
    }
    for(int i = 0; i < n; i++){
      if(nums[i] > 0) return i + 1;
    }
    return n + 1;
  }
};

int main(){
  vector<int> nums{3, 4, -1, 1};
  Solution sol;
  cout << sol.firstMissingPositive(nums) << endl;
}
