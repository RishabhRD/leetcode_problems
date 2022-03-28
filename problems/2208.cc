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
  int halveArray(vector<int> &nums) {
    priority_queue<double> pq{ cbegin(nums), cend(nums) };
    int steps = 0;
    double reduced = 0;
    auto const half_sum = accumulate(begin(nums), end(nums), 0.0) / 2;
    while (half_sum - reduced > 0) {
      auto const top = pq.top() / 2;
      pq.pop();
      ++steps;
      reduced += top;
      pq.push(top);
    }
    return steps;
  }
};
