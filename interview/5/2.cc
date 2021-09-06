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
  int minCost(string s, vector<int> &cost) {
    const int n = size(s);
    char prev_char = 0;
    int starting_point = 0;
    const auto beg = cbegin(cost);
    int res = 0;
    for (int i = 0; i <= n; i++) {
      const char cur_char = s[i];
      if (cur_char != prev_char) {
        if (i - starting_point > 1) {
          int sum = accumulate(beg + starting_point, beg + i, 0);
          int max_ele = *max_element(beg + starting_point, beg + i);
          res += (sum - max_ele);
        }
        starting_point = i;
        prev_char = cur_char;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  string str = "aabaa";
  vector<int> cost = {1, 2, 3, 4, 1};
  cout << sol.minCost(str, cost) << endl;
}
