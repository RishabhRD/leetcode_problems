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
  int minSwap(vector<int> &nums1, vector<int> &nums2) {
    auto const n = size(nums1);
    int const inf = n + 1;
    int with_swap = 1;
    int without_swap = 0;
    for (size_t i = 1; i < n; i++) {
      int const old_with_swap = exchange(with_swap,
        1
          + min(
            ((nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) ? with_swap
                                                                  : inf),
            ((nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) ? without_swap
                                                                  : inf)));
      without_swap =
        min(((nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) ? without_swap
                                                                  : inf),
          ((nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) ? old_with_swap
                                                                : inf));
    }
    return min(with_swap, without_swap);
  }
};
