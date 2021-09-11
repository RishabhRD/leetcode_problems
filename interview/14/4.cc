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

class Solution {
  unordered_map<string, vector<string>> m;

  vector<string> combine(string word, vector<string> prev) {
    for (int i = 0; i < prev.size(); ++i) { prev[i] += " " + word; }
    return prev;
  }

public:
  vector<string> wordBreak(string s, vector<string> &dict) {
    unordered_set<string> mp;
    for (const auto &str : mp) { mp.insert(str); }
    return wordBreak(s, mp);
  }
  vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
    unordered_map<int, vector<string>> memo{ { s.size(), { "" } } };
    function<vector<string>(int)> sentences = [&](int i) {
      if (!memo.count(i))
        for (int j = i + 1; j <= s.size(); j++)
          if (wordDict.count(s.substr(i, j - i)))
            for (string tail : sentences(j))
              memo[i].push_back(
                s.substr(i, j - i) + (tail == "" ? "" : ' ' + tail));
      return memo[i];
    };
    return sentences(0);
  }
};
