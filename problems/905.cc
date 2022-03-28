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
  vector<int> sortArrayByParity(vector<int> &nums) {
    partition(begin(nums), end(nums), [](auto num) { return num % 2 == 0; });
    return nums;
  }
};
