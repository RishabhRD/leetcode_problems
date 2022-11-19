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

using ll = long long;

class Solution {
 public:
  std::vector<std::vector<std::string>> mostPopularCreator(
      std::vector<std::string>& creators, std::vector<std::string>& ids,
      std::vector<int>& views) {
    auto const n = std::size(creators);
    std::unordered_map<std::string_view, ll> view_count;
    std::unordered_map<std::string_view, std::pair<ll, std::string_view>>
        id_map;
    for (int i = 0; i < n; ++i) {
      std::string_view creator = creators[i];
      std::string_view id = ids[i];
      auto view = views[i];
      view_count[creator] += view;
      if (id_map.find(creator) == id_map.end()) {
        id_map[creator] = {view, id};
      } else {
        auto old_view = id_map[creator].first;
        auto old_id = id_map[creator].second;
        if (old_view < view) {
          id_map[creator] = {view, id};
        } else if (old_view == view) {
          id_map[creator] = {view, std::min(old_id, id)};
        }
      }
    }
    auto max_view_count =
        std::max_element(std::begin(view_count), std::end(view_count),
                         [](auto a, auto b) { return a.second < b.second; })
            ->second;
    std::vector<std::vector<std::string>> ans;
    for (auto [creator, cnt] : view_count) {
      if (cnt == max_view_count) {
        ans.push_back(std::vector(
            {std::string(creator), std::string(id_map[creator].second)}));
      }
    }
    return ans;
  }
};
