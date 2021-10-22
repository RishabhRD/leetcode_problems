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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      using ti = tuple<int, int, int>;
      priority_queue<ti, vector<ti>, greater<>> pq;
      const int m = size(matrix);
      const int n = size(matrix[0]);
      for(int i = 0; i < min(m, k); i++){
        pq.emplace(matrix[i][0], i, 0);
      }
      int ans = 0;
      for(int i = 0; i < k; i++){
        auto [answer, row, col] = pq.top();
        pq.pop();
        ans = answer;
        if(col + 1 < n){
          pq.emplace(matrix[row][col + 1], row, col + 1);
        }
      }
      return ans;
    }
};
