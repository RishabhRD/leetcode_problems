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
    int minSwaps(string s) {
      int swaps = 0;
      const int n = size(s);
      int i = 0;
      int j = n - 1;
      int cnt = 0;
      for(int i = 0; i < n; i++){
        if(s[i] == '[') cnt++;
        else cnt--;
        if(cnt < 0){
          while(i < j and s[j] == ']'){
            j--;
          }
          swap(s[i], s[j]);
          swaps++;
          cnt = 1;
        }
      }
      return swaps;
    }
};
