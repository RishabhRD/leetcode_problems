#include <random>
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
  vector<int> orig;

public:
  Solution(vector<int> &nums) : orig(nums) {}

  vector<int> reset() { return orig; }

  vector<int> shuffle() {
    auto shuffled{ orig };
    random_shuffle(begin(shuffled), end(shuffled));
    return shuffled;
  }
};
