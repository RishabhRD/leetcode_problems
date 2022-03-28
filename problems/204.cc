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
  int countPrimes(int n) {
    int cnt = 0;
    vector is_prime(n + 1, true);
    for (int i = 2; i < n; i++) {
      if (is_prime[i]) {
        cnt++;
        for (int j = 2; i * j < n; j++) { is_prime[i * j] = false; }
      }
    }
    return cnt;
  }
};
