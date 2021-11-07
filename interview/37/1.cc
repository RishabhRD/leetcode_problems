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
  bool isMonotonic(vector<int> &arr) {
    bool dec = true;
    bool inc = true;
    for(int i = 0; i < size(arr) - 1; i++){
      if(arr[i] > arr[i + 1]){
        inc = false;
      }else if(arr[i] < arr[i + 1]){
        dec = false;
      }
    }
    return inc or dec;
  }
};
