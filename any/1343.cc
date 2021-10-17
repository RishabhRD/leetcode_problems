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
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    const size_t n = size(arr);
    auto avg = [&](auto sum){
      return sum / (double)(k);
    };
    auto cur_sum = accumulate(cbegin(arr), cbegin(arr) + k, 0);
    int ans = (avg(cur_sum) >= threshold) ? 1 : 0;
    for(size_t i = 0; i < n - k; i++){
      cur_sum -= arr[i];
      cur_sum += arr[i + k];
      ans += (avg(cur_sum) >= threshold) ? 1 : 0;
    }
    return ans;
  }
};
