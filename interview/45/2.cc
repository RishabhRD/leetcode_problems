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

void print(vector<char> const &tasks) {
  for (auto c : tasks) cout << c << ' ';
  cout << '\n';
}

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int max_cnt = 0;
    char max_cnt_var;
    unordered_map<char, int> freq;
    for (auto c : tasks) {
      freq[c]++;
      if (freq[c] > max_cnt) {
        max_cnt = freq[c];
        max_cnt_var = c;
      }
    }
    freq.erase(max_cnt_var);
    int num_idle = n * (max_cnt - 1);
    for (auto [k, cnt] : freq) {
      if (cnt == max_cnt)
        num_idle -= (cnt - 1);
      else
        num_idle -= cnt;
    }
    if (num_idle < 0) num_idle = 0;
    return size(tasks) + num_idle;
  }
};

int main() {
  std::vector<char> res{ 'A', 'A', 'A', 'B', 'B', 'B' };
  Solution sol;
  sol.leastInterval(res, 2);
}
