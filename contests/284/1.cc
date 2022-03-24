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
  vector<int> findKDistantIndices(vector<int> const &nums, int key, int k) {
    set<int> res;
    auto first = find(begin(nums), end(nums), key);
    auto last = end(nums);
    while (first != last) {
      auto const idx = first - begin(nums);
      for (int i = -k; i <= k; ++i) {
        if (idx + i >= 0 and idx + i < size(nums)) res.insert(idx + i);
      }
      first = find(next(first), end(nums), key);
    }
    return vector<int>{ begin(res), end(res) };
  }
};
