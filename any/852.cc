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
  int peakIndexInMountainArray(vector<int> &arr) {
    int low = 0;
    int high = size(arr) - 1;
    auto at = [&](int idx) {
      if (idx < 0)
        return -1;
      else if (idx >= size(arr))
        return (int)1e6 + 1;
      else
        return arr[idx];
    };
    while (low <= high) {
      int mid = (low + high) / 2;
      if (at(mid) > at(mid - 1) and at(mid) > at(mid + 1))
        return mid;
      else if (at(mid) < at(mid - 1))
        high = mid - 1;
      else
        low = mid + 1;
    }
    return 0;
  }
};
