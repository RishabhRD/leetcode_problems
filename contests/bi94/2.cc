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
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

class Solution {
 public:
  std::vector<int> topStudents(std::vector<std::string>& positive_feedback,
                               std::vector<std::string>& negative_feedback,
                               std::vector<std::string>& report,
                               std::vector<int>& student_id, int const k) {
    std::unordered_map<std::string, int> pos;
    std::unordered_map<std::string, int> neg;
    for (auto const& ele : positive_feedback) ++pos[ele];
    for (auto const& ele : negative_feedback) ++neg[ele];
    auto const n = report.size();
    std::vector<std::pair<ll, ll>> res(n);
    for (ll i = 0; i < n; ++i) {
      ll sum = 0;
      std::istringstream iss(report[i]);
      std::string tmp;
      while (getline(iss, tmp, ' ')) {
        sum += 3 * pos[tmp];
        sum -= neg[tmp];
      }
      res[i] = {sum, student_id[i]};
    }
    std::sort(std::begin(res), std::end(res), [](auto a, auto b) {
      if (a.first == b.first) {
        return a.second < b.second;
      } else {
        return a.first > b.first;
      }
    });
    std::vector<int> ans;
    ll total = 0;
    for (auto [_, v] : res) {
      if (total < k) {
        ans.push_back(v);
        ++total;
      }
    }
    return ans;
  }
};
