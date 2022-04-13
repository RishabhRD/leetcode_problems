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
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    array<int, 128> cnt{0};
    array<bool, 128> visited{false};
    for (auto c : s) ++cnt[c];
    string res;
    for (auto c : s) {
      --cnt[c];
      if (not visited[c]) {
        while (not empty(res) and res.back() >= c and cnt[res.back()] != 0) {
          visited[res.back()] = false;
          res.pop_back();
        }
        res += c;
        visited[c] = true;
      }
    }
    return res;
  }
};
