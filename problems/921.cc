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
  int minAddToMakeValid(string s) {
    int ans = 0;
    int count = 0;
    for(char c : s){
      if(c == '('){
        count++;
      }else{
        count--;
        if(count < 0) {
          count = 0;
          ans++;
        }
      }
    }
    ans += count;
    return ans;
  }
};
