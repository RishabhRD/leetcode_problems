#include <bitset>
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
  int hammingWeight(uint32_t n) { return bitset<32>{ n }.count(); }
};
