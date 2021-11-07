#include <queue>
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

int diff(string_view word, string_view other) {
  int cnt = 0;
  for (int i = 0; i < size(word); i++) {
    if (word[i] != other[i]) cnt++;
  }
  return cnt;
}

vector<string_view> get_neighbors(string_view word, vector<string> &wordList) {
  vector<string_view> res;
  for (string_view str : wordList) {
    if (diff(word, str) == 1) { res.push_back(str); }
  }
  return res;
}

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    string_view end = endWord;
    queue<string_view> q;
    q.push(beginWord);
    unordered_set<string_view> visited;
    visited.insert(beginWord);
    int level = 1;
    while (not empty(q)) {
      int n = size(q);
      for (int i = 0; i < n; i++) {
        auto top = q.front();
        q.pop();
        if (top == end) { return level; }
        for (string_view s : get_neighbors(top, wordList)) {
          if (visited.find(s) == visited.end()) {
            q.push(s);
            visited.insert(s);
          }
        }
      }
      level++;
    }
    return 0;
  }
};
