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

void dfs(int num_arrows,
  int i,
  int point,
  vector<int> const &alice_arrows,
  vector<int> &bob_arrows,
  int &max_point,
  vector<int> &max_arr) {
  if (i == 12) {
    bob_arrows[0] += num_arrows;
    if (point > max_point) {
      max_point = point;
      max_arr = bob_arrows;
    }
    bob_arrows[0] -= num_arrows;
    return;
  }
  if (num_arrows - (alice_arrows[i] + 1) >= 0) {
    bob_arrows[i] = alice_arrows[i] + 1;
    dfs(num_arrows - alice_arrows[i] - 1,
      i + 1,
      point + i,
      alice_arrows,
      bob_arrows,
      max_point,
      max_arr);
    bob_arrows[i] = 0;
  }
  dfs(num_arrows, i + 1, point, alice_arrows, bob_arrows, max_point, max_arr);
  bob_arrows[i] = 0;
}

class Solution {
public:
  vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
    vector<int> max_arr;
    int max_point{ 0 };
    vector<int> bob_arrows(12, 0);
    dfs(numArrows, 0, 0, aliceArrows, bob_arrows, max_point, max_arr);
    return max_arr;
  }
};
