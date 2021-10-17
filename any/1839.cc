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
  int longestBeautifulSubstring(string s) {
    int len = 1;
    int cnt = 1;
    int max_len = 0;
    const int n = size(s);
    for(int i = 1; i < n; i++){
      if(s[i] == s[i - 1]){
        len++;
      }else if(s[i] > s[i - 1]){
        len++;
        cnt++;
      }else{
        len = 1;
        cnt = 1;
      }
      if(cnt == 5)
        max_len = max(max_len, len);
    }
    return max_len;
  }
};
