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

using ll = long long;

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, ll> freq;
    std::unordered_map<char, ll> cur_freq;
    for (auto c : t) freq[c]++;
    ll low = 0;
    ll idx = 0;
    ll len = s.size() + 1;
    for (ll high = 0; high < s.size(); ++high) {
      ++cur_freq[s[high]];
      auto const is_good = [&] {
        for (auto [k, v] : freq) {
          if (cur_freq[k] < v) return false;
        }
        return true;
      };
      while (is_good()) {
        if (high - low + 1 < len) {
          len = high - low + 1;
          idx = low;
        }
        --cur_freq[s[low]];
        ++low;
      }
    }
    if (len == s.size() + 1) return "";
    return s.substr(idx, len);
  }
};
