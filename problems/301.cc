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

bool is_valid(const string& str){
  int open = 0;
  for(const auto c : str){
    if(c == '(') open++;
    else if(c == ')') open--;
    if(open < 0) return false;
  }
  return open == 0;
}

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
      vector<string> res;
      queue<string> q;
      unordered_set<string> visited;
      q.push(s);
      visited.insert(s);
      bool found = false;
      while(not empty(q)){
        auto str = q.front();
        q.pop();
        if(is_valid(str)){
          res.push_back(str);
          found = true;
        }
        if(found) continue;
        for(int i = 0; i < size(str); i++){
          if(str[i] != '(' and str[i] != ')'){
            continue;
          }
          auto new_str = str.substr(0, i) + str.substr(i + 1);
          if(visited.find(new_str) == visited.end()){
            q.push(new_str);
            visited.insert(new_str);
          }
        }
      }
      return res;
    }
};
