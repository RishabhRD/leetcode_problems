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

int longest_substring(string_view s, int k){
  int num[128]{0};
  for(auto c : s){
    num[c]++;
  }
  bool flag = true;
  for(auto c : s){
    if(num[c] < k) {
      flag = false;
      break;
    }
  }
  if(flag){
    return size(s);
  }
  int start = 0;
  int result = 0;
  int cur = 0;
  for(cur = 0; cur < size(s); cur++){
    if(num[s[cur]] < k){
      result = max(result, longest_substring(s.substr(start, cur - start), k));
      start = cur + 1;
    }
  }
  result = max(result, longest_substring(s.substr(start), k));
  return result;
}

class Solution {
public:
    int longestSubstring(string s, int k) {
      return longest_substring(s, k);
    }
};
