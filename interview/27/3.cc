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
    vector<int> prevPermOpt1(vector<int>& arr) {
      if(size(arr) <= 1) return arr;
      const int n = size(arr);
      int candid = 0;
      for(int i = n - 2; i >= 0; i--){
        if(arr[i] > arr[i + 1]){
          candid = i;
          break;
        }
      }
      int swp_ind = candid + 1;
      for(int i = candid + 1; i < n; i++){
        if(arr[i] < arr[candid] and arr[i] > arr[swp_ind]){
          swp_ind = i;
        }
      }
      swap(arr[candid], arr[swp_ind]);
      return arr;
    }
};
