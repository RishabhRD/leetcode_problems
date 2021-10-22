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

  vector<int> reset() {
    return orig;
  }

  vector<int> shuffle() {
    vector<int> new_vec(orig);
    unsigned seed = 0;
    std::shuffle(begin(new_vec), end(new_vec), default_random_engine(seed));
    return new_vec;
  }
};
