#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

auto sum(char a, char b) {
  if (a == '1' and b == '1')
    return pair{ '1', '0' };
  else if (a == '0' and b == '0')
    return pair{ '0', '0' };
  else
    return pair{ '0', '1' };
}

auto sum_with_carry(char a, char b, char carry) {
  auto [sum_carry, res] = sum(a, b);
  auto [new_carry, new_res] = sum(res, carry);
  if (new_carry == '1')
    return pair{ new_carry, new_res };
  else
    return pair{ sum_carry, new_res };
}

class Solution {
public:
  string addBinary(string a, string b) {
    char carry = '0';
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    auto at = [](string_view str, int i) {
      if (i >= str.size())
        return '0';
      else
        return str[i];
    };
    int const n = max(size(a), size(b));
    string res;
    for (int i = 0; i < n; i++) {
      auto const [new_carry, bit] = sum_with_carry(at(a, i), at(b, i), carry);
      res.push_back(bit);
      carry = new_carry;
    }
    if (carry == '1') res.push_back('1');
    reverse(begin(res), end(res));
    return res;
  }
};
