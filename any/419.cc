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
    int countBattleships(vector<vector<char>>& board) {
      int cnt = 0;
      for(int i = 0; i < size(board); i++){
        for(int j = 0; j < size(board[0]); j++){
          if(board[i][j] == '.') continue;
          if(i > 0 and board[i - 1][j] == 'X') continue;
          if(j > 0 and board[i][j - 1] == 'X') continue;
          cnt++;
        }
      }
      return cnt;
    }
};
