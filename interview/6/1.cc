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

bool is_self_dividing(int i){
  int cur = i;
  while(cur > 0){
    int divider = cur % 10;
    cur = cur / 10;
    if(divider == 0) return false;
    if(i % divider) return false;
  }
  return true;
}

vector<int> selfDividingNumbers(int left, int right) {
  vector<int> vec;
  for(int i = left; i <= right; i++){
    if(is_self_dividing(i)){
      vec.push_back(i);
    }
  }
  return vec;
}
