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
  int maxScore(vector<int> &cardPoints, int k) {
    const int n = size(cardPoints);
    int lsum = accumulate(cbegin(cardPoints), cbegin(cardPoints) + k, 0);
    int rsum = 0;
    int max_sum = lsum;
    for(int i = 0; i < k; i++){
      rsum += cardPoints[n - i - 1];
      lsum -= cardPoints[k - i - 1];
      max_sum = max(max_sum, lsum + rsum);
    }
    return max_sum;
  }
};
