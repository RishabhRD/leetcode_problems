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

bool dfs(const vector<int>& nums, vector<bool>& visited, int k, int i, int sum, int target){
  if(k == 1) return true;
  if(sum == target) return dfs(nums, visited, k - 1, 0, 0, target);
  for(int j = i; j < size(nums); j++){
    if(!visited[j] and sum + nums[j] <= target){
      visited[j] = true;
      if(dfs(nums, visited, k, j, sum + nums[j], target)) return true;
      visited[j] = false;
    }
  }
  return false;
}

class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    const int sum = accumulate(cbegin(nums), cend(nums), 0);
    if (sum % k != 0 || size(nums) < k) return 0;
    const int n = size(nums);
    vector visited(n, false);
    return dfs(nums, visited, k, 0, 0, sum / k);
  }
};
