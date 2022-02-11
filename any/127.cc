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

auto difference(string_view s1, string_view s2) {
  int diff = 0;
  for (int i = 0; i < size(s1); i++) diff += (s1[i] != s2[i]);
  return diff;
}

auto neighbor(string_view word, vector<string> const &wordList) {
  vector<string_view> neighbors;
  for (string_view str : wordList) {
    if (difference(str, word) == 1) neighbors.push_back(str);
  }
  return neighbors;
}

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    string_view end = endWord;
    queue<string_view> q;
    unordered_set<string_view> visited;
    q.push(beginWord);
    visited.insert(beginWord);
    int cur_level = 1;
    while (not empty(q)) {
      int sz = size(q);
      while (sz--) {
        auto top = q.front();
        q.pop();
        if (top == end) return cur_level;
        for (auto n : neighbor(top, wordList)) {
          if (visited.find(n) == visited.end()) {
            q.push(n);
            visited.insert(n);
          }
        }
      }
      cur_level++;
    }
    return 0;
  }
};

int main() {
  string s1{ "abc" };
  string s2{ "adc" };
  cout << difference(s1, s2) << endl;
}
