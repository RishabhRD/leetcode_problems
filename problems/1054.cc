#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) {
    std::unordered_map<int, int> freq_mp;
    for (auto n : barcodes) ++freq_mp[n];

    using pii = std::pair<int, int>;
    std::priority_queue<pii> pq;
    for (auto [k, v] : freq_mp) {
      pq.push({v, k});
    }

    std::vector<int> res(std::size(barcodes));
    int i = 0;
    while (not empty(pq)) {
      auto [freq, num] = pq.top();
      pq.pop();
      while (freq--) {
        res[i] = num;
        i += 2;
        if (i >= std::size(res)) {
          i = 1;
        }
      }
    }
    return res;
  }
};
