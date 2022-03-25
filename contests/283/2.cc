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

long long get_consecutive_sum(long long start, long long n) {
  if (n <= 0) return 0;
  long long end = start + n - 1;
  return (n * (start + end)) / 2;
}

class Solution {
public:
  long long minimalKSum(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq{ begin(nums), end(nums) };
    int cur = 1;
    long long sum = 0;
    while (not empty(pq) and k > 0) {
      auto top = pq.top();
      pq.pop();
      auto n = min((top - cur), k);
      sum += get_consecutive_sum(cur, n);
      k -= n > 0 ? n : 0;
      cur = top + 1;
    }
    if (k > 0) { sum += get_consecutive_sum(cur, k); }
    return sum;
  }
};
