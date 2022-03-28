#include <queue>
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
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums) {
      pq.emplace(num);
      if (size(pq) > k) { pq.pop(); }
    }
    return pq.top();
  }
};
