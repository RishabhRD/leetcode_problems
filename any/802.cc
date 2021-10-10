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

enum class State{
  not_visited,
  safe,
  unsafe
};

bool dfs(vector<vector<int>>& graph, int cur_node, vector<State>& states){
  if(states[cur_node] != State::not_visited) return states[cur_node] == State::safe;
  states[cur_node] = State::unsafe;
  for(const auto& n : graph[cur_node]){
    if(not dfs(graph, n, states)) return false;
  }
  states[cur_node] = State::safe;
  return true;
}

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      vector<State> states(size(graph), State::not_visited);
      vector<int> ans;
      for(int i = 0; i < size(graph); i++){
        if(dfs(graph, i, states)) ans.push_back(i);
      }
      return ans;
    }
};
