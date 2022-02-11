#include <unordered_set>
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

auto contains(unordered_set<int> const &st, int num) {
  return st.find(num) != st.end();
}

int dfs(unordered_set<int> const &st, int num, unordered_set<int> &visited) {
  if (contains(visited, num)) return 0;
  visited.insert(num);
  int ans = 1;
  if (contains(st, num + 1)) { ans += dfs(st, num + 1, visited); }
  if (contains(st, num - 1)) { ans += dfs(st, num - 1, visited); }
  return ans;
}

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> const st{ begin(nums), end(nums) };
    unordered_set<int> visited;
    int max_len = 0;
    for (auto num : nums) { max_len = max(max_len, dfs(st, num, visited)); }
    return max_len;
  }
};
