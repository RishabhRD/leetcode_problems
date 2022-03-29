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
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    array<int, 128> freq{0};
    for (auto c : s) ++freq[c];
    priority_queue<pair<char, int>> pq;
    for (auto c = 'a'; c <= 'z'; ++c) {
      if (freq[c] != 0) {
        pq.push({c, freq[c]});
      }
    }
    ostringstream os;
    int cur_num = 0;
    while (not empty(pq)) {
      auto [c, freq] = pq.top();
      pq.pop();
      if (cur_num < repeatLimit) {
        ++cur_num;
        os << c;
        --freq;
        if (freq != 0) {
          pq.push({c, freq});
        } else {
          cur_num = 0;
        }
      } else {
        if (pq.empty()) break;
        auto [c1, freq1] = pq.top();
        pq.pop();
        --freq1;
        os << c1;
        if (freq1 != 0) {
          pq.push({c1, freq1});
        }
        pq.push({c, freq});
        cur_num = 0;
      }
    }
    return os.str();
  }
};
