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
  long long countPairs(vector<int>& nums, int k) {
    long long cnt = 0;
    unordered_map<long long, int> gcds;
    for (auto num : nums) {
      long long cur_gcd = gcd(num, k);
      for (auto [old_gcd, old_gcd_cnt] : gcds) {
        if (cur_gcd * old_gcd % k == 0) {
          cnt += old_gcd_cnt;
        }
      }
      ++gcds[cur_gcd];
    }
    return cnt;
  }
};
