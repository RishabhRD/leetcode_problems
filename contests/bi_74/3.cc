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

void print(vector<double> &nums) {
  for (auto num : nums) cout << num << ' ';
  cout << endl;
}

class Solution {
public:
  int halveArray(vector<int> const &nums) {
    int const n = size(nums);
    vector<double> arr{ begin(nums), end(nums) };
    auto const half_sum = accumulate(begin(nums), end(nums), 0.0) / 2;
    priority_queue<double> pq{ begin(nums), end(nums) };
    double reduced = 0;
    int steps = 0;
    while (pq.top()) {
      auto const top = pq.top() / 2;
      pq.pop();
      reduced += top;
      ++steps;
      if (reduced >= half_sum) { return steps; }
      pq.push(top);
    }
    return steps;
  }
};

int main() {
  vector<int> nums{ 6, 58, 10, 84, 35, 8, 22, 64, 1, 78, 86, 71, 77 };
  Solution sol;
  cout << sol.halveArray(nums) << endl;
}
