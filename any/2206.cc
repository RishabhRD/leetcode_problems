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
  bool divideArray(vector<int> &nums) {
    vector cnt(501, 0);
    for (auto num : nums) ++cnt[num];
    return all_of(begin(cnt), end(cnt), [](auto num) { return num % 2 == 0; });
  }
};
