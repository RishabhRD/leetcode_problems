#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum % 2) return {};
    long long cur = 2;
    vector<long long> res;
    while (finalSum != 0) {
      auto const new_sum = finalSum - cur;
      if (new_sum > cur) {
        res.push_back(cur);
        cur += 2;
        finalSum = new_sum;
      } else {
        res.push_back(finalSum);
        finalSum = 0;
      }
    }
    return res;
  }
};
