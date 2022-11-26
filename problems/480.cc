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
  std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    std::multiset<ll> leftS;
    std::multiset<ll> rightS;
    auto const enforceConstraint = [&] {
      if (rightS.size() > leftS.size()) {
        leftS.insert(*rightS.begin());
        rightS.erase(rightS.begin());
      } else if (leftS.size() - rightS.size() > 1) {
        rightS.insert(*leftS.rbegin());
        leftS.erase(leftS.find(*leftS.rbegin()));
      }
    };

    auto const erase = [&](ll i) {
      if (leftS.find(i) != leftS.end()) {
        leftS.erase(leftS.find(i));
      } else {
        rightS.erase(rightS.find(i));
      }
      enforceConstraint();
    };

    auto const insert = [&](ll i) {
      if (leftS.empty())
        leftS.insert(i);
      else {
        auto const leftMax = *leftS.rbegin();
        if (i <= leftMax) {
          leftS.insert(i);
        } else {
          rightS.insert(i);
        }
      }
      enforceConstraint();
    };

    std::vector<double> res;
    ll low = 0;
    auto const n = std::size(nums);
    for (ll high = 0; high < n; ++high) {
      insert(nums[high]);
      while (high - low + 1 > k) {
        erase(nums[low]);
        ++low;
      }
      if (high - low + 1 == k) {
        if (leftS.size() == rightS.size()) {
          res.push_back((*leftS.rbegin() + *rightS.begin()) / 2.0);
        } else {
          res.push_back(*leftS.rbegin());
        }
      }
    }
    return res;
  }
};
