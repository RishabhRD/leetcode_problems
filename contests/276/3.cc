#include <algorithm>
#include <array>
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

using namespace std;

int reverse(int n) {
  int reversed_number = 0;
  while (n != 0) {
    int remainder = n % 10;
    reversed_number = reversed_number * 10 + remainder;
    n /= 10;
  }
  return reversed_number;
}

long long kdig_palindrome(int n, long long k) {
  if (k == 1) return n < 10 ? n : -1;
  auto len = k;
  if (k % 2) {
    k = k / 2;
  } else {
    k = k / 2 - 1;
  }
  auto ans = (n - 1) + pow(10, k);
  if (len - (k + 1) == k + 1) {
    auto r = reverse(ans);
    ans = ans * pow(10, len - 2) + r;
  } else {
    auto r = reverse(ans / 10);
    ans = ans * pow(10, len - 2) + r;
  }
  if (ans >= pow(10, len))
    return -1;
  else
    return ans;
}

class Solution {
 public:
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    vector<long long> res(size(queries));
    transform(begin(queries), end(queries), begin(res), [intLength](auto num) {
      return kdig_palindrome(num, intLength);
    });
    return res;
  }
};
