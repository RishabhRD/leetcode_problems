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

auto get_graph(int n, vector<vector<int>>& edges, vector<double> succProb){
  vector<vector<pair<int, double>>> graph(n);
  for(size_t i = 0; i < size(edges); i++){
    graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
    graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
  }
  return graph;
}

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      using pii = pair<double, int>;
      const auto graph = get_graph(n, edges, succProb);
      vector<double> dist(n, 0);
      priority_queue<pii> pq;
      dist[start] = 1;
      pq.emplace(dist[start], start);
      while(not empty(pq)){
        const auto [cur_dist, cur_node] = pq.top();
        pq.pop();
        for(const auto [node, weight] : graph[cur_node]){
          if(dist[node] < dist[cur_node] * weight){
            dist[node] = dist[cur_node] * weight;
            pq.emplace(dist[node], node);
          }
        }
      }
      return dist[end];
    }
};
