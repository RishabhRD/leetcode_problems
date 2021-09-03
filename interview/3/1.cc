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
    bool judgeCircle(string moves) {
      int cur_x = 0;
      int cur_y = 0;
      for(auto c : moves){
        if(c == 'L'){
          cur_x--;
        }else if(c == 'R'){
          cur_x++;
        }else if(c == 'U'){
          cur_y++;
        }else{
          cur_y--;
        }
      }
      return cur_x == 0 and cur_y == 0;
    }
};
