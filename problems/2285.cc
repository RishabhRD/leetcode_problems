#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>> const& roads) {
    std::vector indegree(n, 0ll);
    for (auto const& road : roads) {
      ++indegree[road[0]];
      ++indegree[road[1]];
    }
    sort(begin(indegree), end(indegree));
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += indegree[i] * (i + 1);
    }
    return sum;
  }
};
