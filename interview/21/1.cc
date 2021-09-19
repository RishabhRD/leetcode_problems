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
    int mySqrt(int x) {
      int low = 0;
      int high = x;
      while(low < high){
        long long mid = ceil((double)(low + high) / 2);
        long long res = mid * mid;
        if(res == x) {
          return mid;
        }else if(res > x){
          high = mid - 1;
        }else{
          low = mid;
        }
      }
      return low;
    }
};

int main(){
  Solution sol;
  cout << sol.mySqrt(8) << endl;
}
