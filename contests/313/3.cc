#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    auto const b1 = std::bitset<32>(num1);
    auto const b2 = std::bitset<32>(num2);
    auto const n1 = b1.count();
    auto const n2 = b2.count();
    if (n1 == n2)
      return num1;
    else if (n1 > n2) {
      std::bitset<32> bs(0);
      int rem = n2;
      for (int i = 31; i >= 0; i--) {
        if (b1[i] and rem) {
          bs[i] = true;
          --rem;
        }
      }
      return bs.to_ulong();
    } else {
      std::bitset<32> bs(0);
      int rem = n2;
      for (int i = 31; i >= 0; i--) {
        if (b1.test(i)) {
          bs.set(i);
          --rem;
        }
      }
      for (int i = 0; i < 32; ++i) {
        if (rem and b1[i] == false) {
          bs[i] = true;
          --rem;
        }
      }
      return bs.to_ulong();
    }
  }
};
