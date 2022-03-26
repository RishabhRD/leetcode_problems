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
  int mostFrequent(vector<int> &nums, int key) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < size(nums) - 1; i++) {
      vec.emplace_back(nums[i], nums[i + 1]);
    }
    vec.erase(
      remove_if(
        begin(vec), end(vec), [key](auto ele) { return ele.first != key; }),
      end(vec));
    unordered_map<int, int> freq;
    for (auto [k, v] : vec) { ++freq[v]; }
    return accumulate(begin(freq),
      end(freq),
      pair{ 0, 0 },
      [](auto a, auto b) -> pair<int, int> {
        if (a.second > b.second)
          return a;
        else
          return b;
      })
      .first;
  }
};
