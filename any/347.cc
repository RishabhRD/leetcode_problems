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
    for (auto num : nums) mp[num]++;
    priority_queue<pair<int, int>> pq;
    vector<int> res;
    for (auto [ele, n] : mp) {
      pq.emplace(n, ele);
      if (size(pq) > (int)size(mp) - k) {
        res.push_back(pq.top().second);
        pq.pop();
      }
    }
    return res;
  }
};
