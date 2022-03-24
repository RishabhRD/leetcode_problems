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

auto to_string(pair<int, int> p) {
  return to_string(p.first) + "_"s + to_string(p.second);
}

class Solution {
public:
  int digArtifacts(int n,
    vector<vector<int>> const &artifacts,
    vector<vector<int>> &dig) {
    unordered_map<string, int> art_mp;
    for (int art_i = 0; art_i < size(artifacts); ++art_i) {
      auto const &art = artifacts[art_i];
      for (int i = art[0]; i <= art[2]; ++i) {
        for (int j = art[1]; j <= art[3]; ++j) {
          art_mp[to_string(pair{ i, j })] = art_i;
        }
      }
    }
    for (auto const &d : dig) { art_mp.erase(to_string(pair{ d[0], d[1] })); }
    unordered_set<int> idx_set;
    for (auto &[k, v] : art_mp) { idx_set.insert(v); }
    return size(artifacts) - size(idx_set);
  }
};
