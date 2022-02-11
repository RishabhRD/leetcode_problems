#include <sstream>
#include <unordered_set>
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

string flatten(vector<string_view> const &res) {
  return accumulate(next(begin(res)),
    end(res),
    string{ res.front() },
    [](string_view s1, string_view s2) {
      stringstream ss;
      ss << s1;
      ss << " ";
      ss << s2;
      return ss.str();
    });
}

void dfs(string_view s,
  unordered_set<string_view> const &words,
  int cur_idx,
  vector<string_view> &cur,
  vector<string> &res) {
  if (cur_idx == size(s)) {
    res.push_back(flatten(cur));
    return;
  }
  for (int i = cur_idx; i < size(s); i++) {
    auto check_str = s.substr(cur_idx, i - cur_idx + 1);
    if (words.find(check_str) != words.end()) {
      cur.push_back(check_str);
      dfs(s, words, i + 1, cur, res);
      cur.pop_back();
    }
  }
}

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string_view> words{ begin(wordDict), end(wordDict) };
    vector<string> res;
    vector<string_view> cur;
    dfs(s, words, 0, cur, res);
    return res;
  }
};
