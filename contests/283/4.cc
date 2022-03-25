#include <unordered_map>
#include <list>
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
  vector<int> replaceNonCoprimes(vector<int> const &nums) {
    vector<int> res;
    for (auto num : nums) {
      while (not empty(res) && gcd(res.back(), num) != 1) {
        auto top = res.back();
        res.pop_back();
        num = lcm(num, top);
      }
      res.push_back(num);
    }
    return res;
  }
};
