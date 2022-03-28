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
  void duplicateZeros(vector<int> &arr) {
    int const n = size(arr);
    int const num_extra = count(cbegin(arr), cend(arr), 0);
    int j = n + num_extra - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (j < n) arr[j] = arr[i];
      j--;
      if (arr[i] == 0) {
        if (j < n) arr[j] = arr[i];
        j--;
      }
    }
  }
};
