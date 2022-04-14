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

constexpr int mod = 1e9 + 7;

class Solution {
 public:
  int maximumProduct(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq{begin(nums), end(nums)};
    while (k--) {
      auto top = pq.top();
      pq.pop();
      ++top;
      pq.push(top);
    }
    long long ans = 1;
    while (not empty(pq)) {
      ans = (ans * pq.top()) % mod;
      pq.pop();
    }
    return ans;
  }
};
