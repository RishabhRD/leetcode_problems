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
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
      unordered_map<int, int> mp;
      for(int i = 0; i < size(c); i++){
        for(int j = 0; j < size(d); j++){
          mp[c[i] + d[j]]++;
        }
      }
      int cnt = 0;
      for(int i = 0; i < size(a); i++){
        for(int j = 0; j < size(b); j++){
          cnt += mp[-(a[i] + b[j])];
        }
      }
      return cnt;
    }
};
