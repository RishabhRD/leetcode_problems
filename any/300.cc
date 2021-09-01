#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

template<typename Container>
void print(const Container& c){
  for(auto x : c){
    cout << x << " ";
  }
  cout << endl;
}

int get_pos(const vector<int>& dp, int k){
  int low = 0;
  int high = size(dp) - 1;
  while(low < high){
    int mid = (low + high) / 2;
    if(dp[mid] < k){
      low = mid + 1;
    }else{
      high = mid;
    }
  }
  return low;
}

int lengthOfLIS(const vector<int> &nums) {
  vector<int> dp;
  const int n = size(nums);
  dp.push_back(nums[0]);
  for(int i = 1; i < n; i++){
    if(dp.back() < nums[i]){
      dp.push_back(nums[i]);
    }else{
      auto pos = get_pos(dp, nums[i]);
      dp[pos] = nums[i];
    }
  }
  return size(dp);
}

int main(){
  cout << lengthOfLIS({10,9,2,5,3,7,101,18}) << endl;
}
