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

// 0	0000
// 1	0001
// 2	0010
// 3	0011
// 4	0100
// 5	0101
// 6	0110
// 7	0111
// 8	1000
// 9	1001
// 10	1010
// 11	1011
// 12	1100
// 13	1101
// 14	1110
// 15	1111

int p2(int x) { return 1 << x; }

int get_max_2_power(int n) {
  int x = 0;
  while (p2(x) <= n) x++;
  return x - 1;
}

class Solution {
public:
  int countSetBits(int n) {
    if (n == 0) return 0;
    int x = get_max_2_power(n);
    int till_2_power_sum = p2(x - 1) * x;
    int msb_remaining_sum = n - p2(x) + 1;
    int without_msb_sum = countSetBits(n - p2(x));
    return till_2_power_sum + msb_remaining_sum + without_msb_sum;
  }
};
