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

int hr_part(char a, char b) {
  if (a == '?') {
    if (b == '?') {
      return 24;
    } else {
      if (b > '3') {
        return 2;
      } else {
        return 3;
      }
    }
  } else {
    if (b == '?') {
      if (a == '2')
        return 4;
      else
        return 10;
    } else {
      return 1;
    }
  }
}

int third_value(char c) {
  if (c == '?')
    return 6;
  else
    return 1;
}

int fourth_value(char c) {
  if (c == '?')
    return 10;
  else
    return 1;
}

class Solution {
 public:
  int countTime(std::string time) {
    auto const h = hr_part(time[0], time[1]);
    auto const m1 = third_value(time[3]);
    auto const m2 = fourth_value(time[4]);
    std::cout << h << ' ' << m1 << ' ' << m2 << std::endl;
    return h * m1 * m2;
  }
};
