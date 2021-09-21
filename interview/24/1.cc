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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
      sort(begin(target), end(target));
      sort(begin(arr), end(arr));
      return equal(cbegin(target), cend(target), cbegin(arr), cend(arr));
    }
};
