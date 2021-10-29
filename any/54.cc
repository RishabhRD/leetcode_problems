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

auto get_next_dir(pair<int, int> cur_dir) -> pair<int, int>{
  constexpr static auto right = pair{0, 1};
  constexpr static auto down = pair{1, 0};
  constexpr static auto left = pair{0, -1};
  constexpr static auto up = pair{-1, 0};
  if(cur_dir == right) return down;
  else if(cur_dir == down) return left;
  else if(cur_dir == left) return up;
  else return right;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      const int m = size(matrix);
      const int n = size(matrix[0]);
      auto is_in = [&](int i, int j){
        return i >= 0 and j >= 0 and i < m and j < n;
      };
      vector visited(m, vector(n, false));
      pair<int,int> cur_dir = {0, 1};
      pair<int, int> cur_idx = {0, 0};
      vector<int> result;
      while(true){
        auto [cur_x, cur_y] = cur_idx;
        visited[cur_x][cur_y] = true;
        result.push_back(matrix[cur_x][cur_y]);
        int new_x = cur_x + cur_dir.first;
        int new_y = cur_y + cur_dir.second;
        if(!is_in(new_x, new_y) or visited[new_x][new_y]){
          cur_dir = get_next_dir(cur_dir);
          new_x = cur_x + cur_dir.first;
          new_y = cur_y + cur_dir.second;
          if(!is_in(new_x, new_y) or visited[new_x][new_y]){
            break;
          }else{
            cur_idx = {new_x, new_y};
          }
        }else{
          cur_idx = {new_x, new_y};
        }
      }
      return result;
    }
};
