#include <unordered_set>
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

using graph = unordered_map<string_view, unordered_map<string_view, double>>;

auto get_graph(const vector<vector<string>>& eqns, const vector<double>& values){
  graph g;
  for(int i = 0; i < size(values); i++){
    const string_view a = eqns[i][0];
    const string_view b = eqns[i][1];
    g[a][b] = values[i];
    g[b][a] = 1 / values[i];
  }
  return g;
}

template <typename Container, typename Ele>
bool contains(const Container& cont, const Ele& ele){
  return cont.find(ele) != end(cont);
}

double dfs(graph& g, string_view start, string_view end, unordered_set<string_view>& visited){
  if(not contains(g, start)){
    return -1;
  }
  if(contains(g[start], end)){
    return g[start][end];
  }
  visited.insert(start);
  for(auto& [str, w] : g[start]){
    if(!contains(visited, str)){
      auto val = dfs(g, str, end, visited);
      if(val != -1){
        return w * val;
      }
    }
  }
  return -1;
}

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
    vector<double> &values,
    vector<vector<string>> &queries) {
    auto g = get_graph(equations, values);
    vector<double> ans;
    for(const auto& query : queries){
      unordered_set<string_view> visited;
      ans.push_back(dfs(g, query[0], query[1], visited));
    }
    return ans;
  }
};
