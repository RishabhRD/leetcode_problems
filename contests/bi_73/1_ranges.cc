#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int mostFrequent(vector<int>& nums, int key) {
    auto iter = nums | views::adjacent<2> |
                views::filter([](auto ele) { return ele.first == key; }) |
                views::transform([](auto ele) { return ele.second; });
    unordered_map<int, int> freq_cnt;
    for (auto ele : iter) {
      ++freq_cnt[ele];
    }
    return ranges::max_element(
               freq_cnt,
               [](auto prev, auto ele) { return prev.second < ele.second; })
        ->first;
  }
};
