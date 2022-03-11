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
  vector<int> findAnagrams(string s, string p) {
    int const n = size(s);
    int const m = size(p);
    if (m > n) return {};
    array<int, 128> s_freq{ 0 };
    array<int, 128> p_freq{ 0 };
    for (auto c : p) p_freq[c]++;
    int i = 0;
    for (; i < m; i++) { s_freq[s[i]]++; }
    vector<int> res;
    if (s_freq == p_freq) { res.push_back(i - m); }
    for (; i < n; i++) {
      s_freq[s[i - m]]--;
      s_freq[s[i]]++;
      if (s_freq == p_freq) { res.push_back(i - m + 1); }
    }
    return res;
  }
};
