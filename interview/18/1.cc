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
    int findSpecialInteger(vector<int>& arr) {
      const int n = size(arr);
      for(auto ele : {arr[n / 4], arr[n / 2], arr[3*n / 4]}){
        auto pos = lower_bound(cbegin(arr), cend(arr), ele);
        if(*(pos + n / 4) == ele) return ele;
      }
      return -1;
    }
};
