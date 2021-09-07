#include <map>
#include <limits>
#include <unordered_map>
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

double slope(vector<int> &p1, vector<int> &p2) {
  int dx = p2[0] - p1[0];
  if(dx == 0) return numeric_limits<double>::infinity();
  int dy = p2[1] - p1[1];
  return (double)dy / (double)dx;
}

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    const int n = size(points);
    int res = 1;
    for (int i = 0; i < n; i++) {
      unordered_map<double, int> mp;
      for (int j = i + 1; j < n; j++) {
          auto slp = slope(points[i], points[j]);
          mp[slp]++;
      }
      for (const auto &[k, v] : mp) { res = max(res, v + 1); }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> pts = {
    { 1, 1 }, { 3, 2 }, { 5, 3 }, { 4, 1 }, { 2, 3 }, { 1, 4 }
  };
  Solution sol;
  cout << sol.maxPoints(pts) << endl;
}
