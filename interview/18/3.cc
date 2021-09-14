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
    int kthSmallest(vector<vector<int>>& mat, int k) {
      vector<int> sums(mat[0]);
      for(int i = 1; i < size(mat); i++){
        vector<int> new_sums;
        for(auto x : mat[i]){
          for(auto sum : sums){
            new_sums.push_back(sum + x);
          }
        }
        sort(begin(new_sums), end(new_sums));
        new_sums.resize(min(k, int(size(new_sums))));
        sums = move(new_sums);
      }
      return sums[k - 1];
    }
};
