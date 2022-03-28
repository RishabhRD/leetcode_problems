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

void dfs(const vector<vector<int>> &graph, int cur, vector<bool> &visited) {
  visited[cur] = true;
  for (auto n : graph[cur]) {
    if (not visited[n]) dfs(graph, n, visited);
  }
}

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    vector<bool> visited(size(rooms));
    dfs(rooms, 0, visited);
    return all_of(cbegin(visited), cend(visited), [](bool b) { return b; });
  }
};
