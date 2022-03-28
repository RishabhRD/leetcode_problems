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

auto get_graph(const vector<vector<int>> &times, const int n){
  vector<vector<pair<int, int>>> graph(n + 1);
  for(const auto& edge : times){
    graph[edge[0]].emplace_back(edge[1], edge[2]);
  }
  return graph;
}

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    constexpr static int inf = 1e9;
    const auto graph = get_graph(times, n);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, inf);
    dist[k] = 0;
    pq.emplace(0, k);
    while(not empty(pq)){
      const auto [cur_dist, cur_node] = pq.top();
      pq.pop();
      for(const auto [node, weight] : graph[cur_node]){
        if(dist[node] > dist[cur_node] + weight){
          dist[node] = dist[cur_node] + weight;
          pq.emplace(dist[node], node);
        }
      }
    }
    int ans = *max_element(next(cbegin(dist)), cend(dist));
    return (ans == inf) ? -1 : ans;
  }
};
