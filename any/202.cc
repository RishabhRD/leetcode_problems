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

int dss(int num){
  int sum = 0;
  while(num != 0){
    int dig = num % 10;
    sum += dig * dig;
    num /= 10;
  }
  return sum;
}

class Solution {
public:
    bool isHappy(int n) {
      int slow = n, fast = n;
      do {
        slow = dss(slow);
        fast = dss(dss(fast));
      }while(slow != fast);
      return slow == 1;
    }
};
