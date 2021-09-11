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
  int snakesAndLadders(const vector<vector<int>> &board) {
    const int N = size(board);
    vector<int> new_board;
    new_board.push_back(0);
    bool alternate = false;
    for (auto itr = crbegin(board); itr != crend(board); itr++) {
      const auto& vec = *itr;
      if (alternate) {
        copy(crbegin(vec), crend(vec), back_inserter(new_board));
      } else {
        copy(cbegin(vec), cend(vec), back_inserter(new_board));
      }
      alternate = !alternate;
    }
    /* int cur = 1; */
    /* for (int i = 0; i < N; i++) { */
    /*   for (int j = 0; j < N; j++) { cout << new_board[cur++] << ' '; } */
    /*   cout << endl; */
    /* } */
    const int n = N * N;
    queue<int> q;
    vector<bool> visited(n + 1);
    int cur_height = 0;
    auto push = [&](int ele) {
      if (visited[ele]) { return; }
      q.push(ele);
      visited[ele] = true;
    };
    push(1);
    while (not empty(q)) {
      int q_size = size(q);
      while (q_size--) {
        int top = q.front();
        q.pop();
        if (top == n) return cur_height;
        for (int i = 1; i <= 6; i++) {
          if (i + top <= n) {
            if (new_board[i + top] != -1) {
              push(new_board[i + top]);
            } else {
              push(i + top);
            }
          }
        }
      }
      cur_height++;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  cout << sol.snakesAndLadders({ { -1, -1 }, { -1, 3 } });
}
