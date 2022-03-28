#include <stack>
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
public:
  string minRemoveToMakeValid(string s) {
    vector<int> st;
    const int n = size(s);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        st.push_back(i);
      } else if (s[i] == ')') {
        if (empty(st)) {
          s[i] = '*';
        } else {
          st.pop_back();
        }
      }
    }
    for (auto n : st) { s[n] = '*'; }
    string res;
    std::copy_if(
      begin(s), end(s), back_inserter(res), [](auto c) { return c != '*'; });
    return res;
  }
};
