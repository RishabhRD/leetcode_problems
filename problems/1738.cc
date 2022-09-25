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

class Solution {
 public:
  int kthLargestValue(std::vector<std::vector<int>>& matrix, int k) {
    auto const m = std::size(matrix);
    auto const n = std::size(matrix[0]);

    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        matrix[i][j] = matrix[i][j] ^ matrix[i][j - 1];
      }
    }

    for (int j = 0; j < n; ++j) {
      for (int i = 1; i < m; ++i) {
        matrix[i][j] = matrix[i][j] ^ matrix[i - 1][j];
      }
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        pq.push(matrix[i][j]);
        if (pq.size() > k) pq.pop();
      }
    }

    return pq.top();
  }
};
