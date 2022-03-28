#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    for (auto const num : nums) mp[num]++;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto [ele, freq] : mp) {
      pq.emplace(freq, ele);
      if (size(pq) > k) pq.pop();
    }
    vector<int> res;
    while (not empty(pq)) {
      auto [freq, ele] = pq.top();
      pq.pop();
      res.push_back(ele);
    }
    return res;
  }
};
