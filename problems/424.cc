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
    int characterReplacement(string s, int k) {
      int max_count = 0;
      int count[26]{0};
      const int n = size(s);
      int i = 0;
      int ans = 0;
      for(int j = 0; j < n; j++){
        max_count = max(max_count, ++count[s[j] - 'A']);
        if(j - i + 1 - max_count > k){
          count[s[i++] - 'A']--;
        }
        ans = max(ans, j - i + 1);
      }
      return ans;
    }
};
