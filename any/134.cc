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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int sum = 0;
      for(size_t i = 0; i < size(gas); i++){
        sum += gas[i] - cost[i];
      }
      if(sum < 0) return -1;
      int accumulated = 0;
      int start_point = 0;
      for(size_t i = 0; i < size(gas); i++){
        int cur_gain = gas[i] - cost[i];
        if(cur_gain + accumulated < 0){
          start_point = i + 1;
          accumulated = 0;
        }else{
          accumulated += cur_gain;
        }
      }
      return start_point;
    }
};
