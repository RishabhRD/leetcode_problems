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

int dfs(std::vector<bool>& visited, int idx, int n) {
  if (idx > n) return 1;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      if (idx % i == 0 || i % idx == 0) {
        visited[i] = true;
        cnt += dfs(visited, idx + 1, n);
        visited[i] = false;
      }
    }
  }
  return cnt;
}

class Solution {
 public:
  int countArrangement(int n) {
    std::vector<bool> visited(n + 1, false);
    return dfs(visited, 1, n);
  }
};
