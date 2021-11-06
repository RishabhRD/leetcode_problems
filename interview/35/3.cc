#include <unordered_set>
#include <queue>
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

vector<string> get_neighbors(string &s1, const string &s2) {
  int i = 0;
  for (; i < size(s1); i++) {
    if (s1[i] != s2[i]) { break; }
  }
  vector<string> res;
  for (int j = i + 1; j < size(s1); j++) {
    if (s1[j] == s2[i]) {
      swap(s1[i], s1[j]);
      res.push_back(s1);
      swap(s1[i], s1[j]);
    }
  }
  return res;
}

class Solution {
public:
  int kSimilarity(string s1, string s2) {
    int level = 0;
    queue<string> q;
    unordered_set<string> st;
    st.insert(s1);
    q.push(s1);
    while (not empty(q)) {
      const int n = size(q);
      for (int i = 0; i < n; i++) {
        auto top = q.front();
        q.pop();
        if (top == s2) { return level; }
        for (auto s : get_neighbors(top, s2)) {
          if (st.find(s) == st.end()) {
            q.push(s);
            st.insert(s);
          }
        }
      }
      level++;
    }
    return -1;
  }
};

/* int main() { */
/*   Solution sol; */
/*   cout << sol.kSimilarity("ab", "ba") << endl; */
/* } */
