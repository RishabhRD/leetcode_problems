#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
  int kIncreasing(vector<int> &arr, int k) {
    int const n = size(arr);
    int res = 0;
    for (int i = 0; i < k; i++) {
      vector<int> dp;
      for (int j = i; j < n; j += k) {
        auto itr = upper_bound(begin(dp), end(dp), arr[j]);
        if (itr == end(dp)) {
          dp.push_back(arr[j]);
        } else {
          *itr = arr[j];
        }
      }
      res += size(dp);
    }
    return n - res;
  }
};
