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

int sigma(int a, int b){
  if(a - b > 0) return 1;
  if(a == b) return 0;
  return -1;
}

class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    const int n = size(arr);
    if(n == 1) return 1;
    int prev_sigma = sigma(arr[0], arr[1]);
    int max_size = prev_sigma == 0 ? 1 : 2;
    int cur_size = max_size;
    for(int j = 1; j < n - 1; j++){
      int cur_sigma = sigma(arr[j], arr[j + 1]);
      if(prev_sigma == 0){
        if(cur_sigma == 0)
          cur_size = 1;
        else
          cur_size = 2;
        max_size = max(max_size, cur_size);
      }else if(cur_sigma == (-prev_sigma)){
        cur_size = cur_size + 1;
        max_size = max(max_size, cur_size);
      }else{
        cur_size = 2;
      }
      prev_sigma = cur_sigma;
    }
    return max_size;
  }
};
