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
    int peakIndexInMountainArray(vector<int>& arr) {
      int low = 0;
      int high = size(arr) - 1;
      int ans = 0;
      auto at = [&](int i){
        if(i < 0) return -1;
        if(i >= size(arr)) return INT32_MAX;
        return arr[i];
      };
      while(low <= high){
        int mid = (low + high) / 2;
        if(at(mid) > at(mid - 1) and at(mid) > at(mid + 1)) {
          ans = mid;
          break;
        }else if(at(mid) > at(mid - 1) and at(mid + 1) > at(mid)){
          low = mid + 1;
        }else{
          high = mid - 1;
        }
      }
      return ans;
    }
};
