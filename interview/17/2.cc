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
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(begin(nums), end(nums));
    const int n = size(nums);
    vector<int> prev(n, -1);
    vector<int> count(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 and count[j] + 1 > count[i]) {
          count[i] = count[j] + 1;
          prev[i] = j;
        }
      }
    }
    int idx = max_element(cbegin(count), cend(count)) - cbegin(count);
    vector<int> res;
    while (idx != -1) {
      res.push_back(nums[idx]);
      idx = prev[idx];
    }
    return res;
  }
};
