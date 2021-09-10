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
  vector<int> vec;
  int cur_val;
  int cur_index;

public:
  Solution(vector<int> &w)
    : vec{ w }, cur_index(0), cur_val(vec[0]) {}

  int pickIndex() {
    if(!(cur_val--)){
      cur_index = (cur_index + 1) % size(vec);
      cur_val = vec[cur_index];
    }
    return cur_index;
  }
};
