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

bool is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool is_correct(std::string_view str) {
  return is_vowel(str.front()) && is_vowel(str.back());
}

class Solution {
 public:
  std::vector<int> vowelStrings(std::vector<std::string>& words,
                                std::vector<std::vector<int>>& queries) {
    ll const n = words.size();
    std::vector<ll> prefix(n);
    prefix[0] = is_correct(words[0]);
    for (ll i = 1; i < n; ++i) {
      prefix[i] = prefix[i - 1] + is_correct(words[i]);
    }
    auto get_ans = [&](ll x, ll y) {
      if (x == 0)
        return prefix[y];
      else
        return prefix[y] - prefix[x - 1];
    };
    std::vector<int> ans;
    for (auto const& q : queries) {
      auto const x = q[0];
      auto const y = q[1];
      ans.push_back(get_ans(x, y));
    }
    return ans;
  }
};
