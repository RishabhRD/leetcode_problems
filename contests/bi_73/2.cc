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
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    auto to_comparable_num = [&](auto num) {
      if (num == 0) return mapping[num];
      auto multiple_factor = 1;
      auto res = 0;
      while (num != 0) {
        auto rem = num % 10;
        num = num / 10;
        res += (multiple_factor * mapping[rem]);
        multiple_factor *= 10;
      }
      return res;
    };
    stable_sort(begin(nums), end(nums), [to_comparable_num](auto a, auto b) {
      return to_comparable_num(a) < to_comparable_num(b);
    });
    return nums;
  }
};
