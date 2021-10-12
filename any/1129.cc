#include <unordered_set>
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

struct Color {
  bool has_red;
  bool has_blue;
};

auto get_graph(int n, const vector<vector<int>>& red_edges, const vector<vector<int>>& blue_edges){
  vector<unordered_set<int>> graph(n);
  vector colors(n, vector<Color>(n));
  for(const auto& e : red_edges){
    graph[e[0]].insert(e[1]);
    colors[e[0]][e[1]].has_red = true;
  }
  for(const auto& e : blue_edges){
    graph[e[0]].insert(e[1]);
    colors[e[0]][e[1]].has_blue = true;
  }
  return pair{graph, colors};
}


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
      const auto [graph, colors] = get_graph(n, red_edges, blue_edges);
      vector<bool> visited(n);
      vector<int> dist(n, -1);
      dist[0] = 0;
      visited[0] = true;
      queue<pair<int, Color>> q;
      for(auto e : graph[0]){
        visited[e] = true;
        q.emplace(e, colors[0][e]);
      }
      int cur_dist = 1;
      while(not empty(q)){
        auto n = size(q);
        while(n--){
          const auto [cur_node, cur_color] = q.front();
          q.pop();
          dist[cur_node] = cur_dist;
          for(const auto node : graph[cur_node]){
            if(not visited[node]){
              auto [has_red, has_blue] = colors[cur_node][node];
              if(cur_color.has_red and cur_color.has_blue){
                q.emplace(node, colors[cur_node][node]);
                visited[node] = true;
              }else if(cur_color.has_red){
                if(has_blue){
                  q.emplace(node, colors[cur_node][node]);
                  visited[node] = true;
                }
              }else{
                if(has_red){
                  q.emplace(node, colors[cur_node][node]);
                  visited[node] = true;
                }
              }
            }
          }
        }
        cur_dist++;
      }
      return dist;
    }
};
