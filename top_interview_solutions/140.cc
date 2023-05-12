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
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

void dfs(ll i, std::string_view s, std::vector<std::string> const& words,
         std::vector<std::string_view>& cur, std::vector<std::string>& res) {
  if (i == s.size()) {
    std::stringstream os;
    for (ll i = 0; i < cur.size(); ++i) {
      std::string_view str = cur[i];
      os << str;
      if (i != cur.size() - 1) os << ' ';
    }
    res.push_back(os.str());
    return;
  }

  for (std::string_view str : words) {
    if (i + str.size() > s.size()) continue;
    if (s.substr(i, str.size()) == str) {
      cur.push_back(str);
      dfs(i + str.size(), s, words, cur, res);
      cur.pop_back();
    }
  }
}

class Solution {
 public:
  std::vector<std::string> wordBreak(std::string s,
                                     std::vector<std::string>& wordDict) {
    std::vector<std::string_view> cur;
    std::vector<std::string> res;
    dfs(0, s, wordDict, cur, res);
    return res;
  }
};
