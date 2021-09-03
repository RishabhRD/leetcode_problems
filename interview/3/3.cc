#include <unordered_map>
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

struct hash_pair {
  template<class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

void dfs(int row,
  int col,
  unordered_map<int, vector<int>> &row_mp,
  unordered_map<int, vector<int>> &col_mp,
  unordered_set<pair<int, int>, hash_pair> &visited) {
  for(auto c : row_mp[row]){
    if(visited.find({row, c}) == visited.end()){
      visited.insert({row, c});
      dfs(row, c, row_mp, col_mp, visited);
    }
  }
  for(auto r : col_mp[col]){
    if(visited.find({r, col}) == visited.end()){
      visited.insert({r, col});
      dfs(r, col, row_mp, col_mp, visited);
    }
  }
}

class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    for (const auto &stone : stones) {
      rows[stone[0]].push_back(stone[1]);
      cols[stone[1]].push_back(stone[0]);
    }
    int count = 0;
    unordered_set<pair<int, int>, hash_pair> visited;
    for (const auto &stone : stones) {
      if(visited.find({stone[0], stone[1]}) == visited.end()){
        visited.insert({stone[0], stone[1]});
        dfs(stone[0], stone[1], rows, cols, visited);
        count++;
      }
    }
    return size(stones) - count;
  }
};

