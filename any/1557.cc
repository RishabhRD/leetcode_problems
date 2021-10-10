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

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      vector<int> num_indegree(n);
      for(const auto& edge : edges){
        num_indegree[edge[1]]++;
      }
      vector<int> res;
      for(int i = 0; i < n; i++){
        if(num_indegree[i] == 0){
          res.push_back(i);
        }
      }
      return res;
    }
};
