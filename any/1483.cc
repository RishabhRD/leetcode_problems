#include <bitset>
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


class TreeAncestor {
  vector<vector<int>> up;

public:
  TreeAncestor(int n, vector<int> &parent) : up(n, vector(20, -1)) {
    for (int i = 0; i < n; i++) { up[i][0] = parent[i]; }
    for (int i = 1; i < 20; i++) {
      for (int node = 0; node < n; node++) {
        int i_1_node = up[node][i - 1];
        if (i_1_node != -1) { up[node][i] = up[i_1_node][i - 1]; }
      }
    }
  }

  int getKthAncestor(int node, int k) {
    bitset<20> bits(k);
    for (int i = 0; i < 20; i++) {
      if (bits.test(i)) {
        node = up[node][i];
        if (node == -1) return -1;
      }
    }
    return node;
  }
};
