#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> watchedVideosByFriends(
      std::vector<std::vector<std::string>>& watchedVideos,
      std::vector<std::vector<int>>& friends, int id, int level) {
    auto const n = std::size(friends);
    std::queue<int> q;
    std::vector<bool> visited(n);
    visited[id] = true;
    q.push(id);
    int cur_level = 0;
    while (not q.empty() and cur_level < level) {
      auto sz = q.size();
      while (sz--) {
        auto const top = q.front();
        q.pop();
        for (auto const& f : friends[top]) {
          if (not visited[f]) {
            visited[f] = true;
            q.push(f);
          }
        }
      }
      ++cur_level;
    }
    std::unordered_map<std::string_view, int> freq_mp;
    while (not std::empty(q)) {
      auto top = q.front();
      q.pop();
      for (std::string_view movie : watchedVideos[top]) {
        ++freq_mp[movie];
      }
    }
    std::vector<std::string> res;
    for (auto [k, v] : freq_mp) {
      res.push_back(std::string(k));
    }
    std::sort(std::begin(res), std::end(res),
              [&](std::string_view a, std::string_view b) {
                if (freq_mp[a] == freq_mp[b]) {
                  return a < b;
                } else {
                  return freq_mp[a] < freq_mp[b];
                }
              });
    return res;
  }
};
