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
  bool isMatch(string s, string p) {
    int s_idx = 0;
    int p_idx = 0;
    const int s_n = size(s);
    const int p_n = size(p);
    int match = 0;
    int star = -1;
    while(s_idx < s_n){
      if(p_idx < p_n and (s[s_idx] == p[p_idx] or p[p_idx] == '?')){
        s_idx++;
        p_idx++;
      } else if(p_idx < p_n and p[p_idx] == '*'){
        star = p_idx;
        match = s_idx;
        p_idx++;
      } else if(star != -1){
        p_idx = star + 1;
        s_idx = ++match;
      }else{
        return false;
      }
    }
    while(p_idx < p_n){
      if(p[p_idx] != '*') return false;
      p_idx++;
    }
    return true;
  }
};
