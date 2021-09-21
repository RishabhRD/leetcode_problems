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
    double trimMean(vector<int>& arr) {
      sort(begin(arr), end(arr));
      const int del_num = 0.05 * size(arr);
      auto low = begin(arr) + del_num;
      if(low >= end(arr)){
        return 0;
      }
      auto high = end(arr) - del_num;
      if(high < begin(arr)){
        return 0;
      }
      return (double)accumulate(low, high, 0) / (high - low);
    }
};

int main(){
  Solution sol;
  vector<int> vec{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
}
