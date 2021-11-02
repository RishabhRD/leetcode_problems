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
  vector<string> removeComments(vector<string> &source) {
    bool comment = false;
    vector<string> ans;
    string new_s;
    for (string_view s : source) {
      const int n = size(s);
      for (int i = 0; i < n; i++) {
        if (!comment && i + 1 < n && s[i] == '/' && s[i + 1] == '/')
          break;
        else if (!comment && i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
          comment = true;
          i++;
        } else if (comment && i + 1 < n && s[i] == '*' && s[i + 1] == '/') {
          comment = false;
          i++;
        } else if (!comment) {
          new_s.push_back(s[i]);
        }
      }
      if (!comment and size(new_s) > 0) {
        ans.push_back(new_s);
        new_s.clear();
      }
    }
    return ans;
  }
};
