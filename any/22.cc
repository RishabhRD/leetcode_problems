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

void add_paren(const int open,
  const int close,
  const int n,
  const string &current,
  vector<string> &res) {
  if(size(current) == 2 * n){
    res.push_back(current);
    return;
  }
  if(n > open){
    add_paren(open + 1, close, n, current + "(", res);
  }
  if(open > close){
    add_paren(open, close + 1, n, current + ")", res);
  }
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> vec;
    add_paren(0, 0, n, ""s, vec);
    return vec;
  }
};
