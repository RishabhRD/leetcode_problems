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

auto get_indgree(const vector<int> &left_child,
  const vector<int> &right_child) {
  vector<int> indegree(size(left_child));
  for(const auto n : left_child){
    if(n >= 0)
      indegree[n]++;
  }
  for(const auto n : right_child){
    if(n >= 0)
      indegree[n]++;
  }
  return indegree;
}

bool dfs(int cur_node,
  const vector<int> &left_child,
  const vector<int> &right_child,
  vector<bool> &visited) {
  if (visited[cur_node]) return false;
  visited[cur_node] = true;
  if (left_child[cur_node] != -1) {
    if(not dfs(left_child[cur_node], left_child, right_child, visited)){
      return false;
    }
  }
  if (right_child[cur_node] != -1) {
    if(not dfs(right_child[cur_node], left_child, right_child, visited)){
      return false;
    }
  }
  return true;
}

class Solution {
public:
  bool validateBinaryTreeNodes(int n,
    vector<int> &left_child,
    vector<int> &right_child) {
    vector<bool> visited(n);
    const auto indegree_vec = get_indgree(left_child, right_child);
    if (not(count(cbegin(indegree_vec), cend(indegree_vec), 0) == 1
            and all_of(cbegin(indegree_vec), cend(indegree_vec), [](int deg) {
                  return deg < 2;
                }))) {
      return false;
    }
    int root =
      find(cbegin(indegree_vec), cend(indegree_vec), 0) - cbegin(indegree_vec);
    return dfs(root, left_child, right_child, visited)
           and count(cbegin(visited), cend(visited), true) == n;
  }
};
