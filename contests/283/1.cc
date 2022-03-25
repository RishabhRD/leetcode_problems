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

class Solution {
public:
  vector<string> cellsInRange(string s) {
    vector<string> res;
    for (auto letter = s[0]; letter <= s[3]; ++letter) {
      for (auto num = s[1]; num <= s[4]; ++num) {
        res.push_back(letter + to_string(num - '0'));
      }
    }
    return res;
  }
};
