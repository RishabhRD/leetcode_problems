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
    int minPartitions(string n) {
      return *max_element(cbegin(n), cend(n)) - '0';
    }
};
