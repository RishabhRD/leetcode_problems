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
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> mp;
      for(auto n : nums){
        mp[n]++;
        if(mp[n] > 1){
          return true;
        }
      }
      return false;
    }
};
