#include <queue>
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
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> pq{cbegin(nums), cend(nums)};
      for(int i = 0; i < k - 1; i++){
        pq.pop();
      }
      return pq.top();
    }
};
