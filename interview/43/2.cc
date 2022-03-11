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

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    reverse(begin(matrix), end(matrix));
    int const n = size(matrix);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) { swap(matrix[i][j], matrix[j][i]); }
    }
  }
};
