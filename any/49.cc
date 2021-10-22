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
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (const auto &str : strs) {
      auto tmp = str;
      sort(begin(tmp), end(tmp));
      mp[tmp].push_back(str);
    }
    vector<vector<string>> res;
    for (const auto &[k, v] : mp) { res.push_back(std::move(v)); }
    return res;
  }
};
