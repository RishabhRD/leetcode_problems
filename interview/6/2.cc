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
  int hIndex(vector<int> &citations) {
    const int n = size(citations);
    sort(begin(citations), end(citations), greater<int>{});
    int res = n;
    for (int i = 0; i < n; i++) {
      if(citations[i] < i + 1){
        res = i;
        break;
      }
    }
    return res;
  }
};
