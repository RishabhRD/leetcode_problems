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

pair<int, int> get_carry(int num, int carry){
  if(carry == 0) return {num, carry};
  if(num <= 8){
    return {num + carry, 0};
  }else{
    return {0, 1};
  }
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      reverse(begin(digits), end(digits));
      int carry = 1;
      for(int& n : digits){
        auto [new_n, new_c] = get_carry(n, carry);
        n = new_n;
        carry = new_c;
      }
      if(carry > 0){
        digits.push_back(carry);
      }
      reverse(begin(digits), end(digits));
      return digits;
    }
};
