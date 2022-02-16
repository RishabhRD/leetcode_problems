#include <queue>
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
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    using tii = tuple<int, int, int>;
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    int const m = size(matrix);
    int const n = size(matrix[0]);
    for (int i = 0; i < m; i++) { pq.emplace(matrix[i][0], i, 0); }
    for (int i = 0; i < k - 1; i++) {
      auto [val, row, col] = pq.top();
      pq.pop();
      if (col + 1 < n) pq.emplace(matrix[row][col + 1], row, col + 1);
    }
    return get<0>(pq.top());
  }
};
