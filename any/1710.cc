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
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(begin(boxTypes), end(boxTypes), [](const auto &a, const auto &b) {
      return a[1] > b[1];
    });
    int sum = 0;
    for (const auto &v : boxTypes) {
      sum += min(truckSize, v[0]) * v[1];
      truckSize -= v[0];
      if (truckSize <= 0) break;
    }
    return sum;
  }
};

int main() {
  vector<vector<int>> dp{ { 1, 3 }, { 2, 2 }, { 3, 1 } };
  Solution sol;
  cout << sol.maximumUnits(dp, 4) << endl;
}
