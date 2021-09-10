#include <unordered_map>
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
    int sumOfUnique(vector<int>& nums) {
      unordered_map<int, int> mp;
      for(auto x : nums){
        mp[x]++;
      }
      int sum = 0;
      for(const auto& [k, v] : mp){
        if(v == 1)
          sum += k;
      }
      return sum;
    }
};
