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

int to_int(string_view str){
  bool neg = false;
  int num = 0;
  for(auto c : str){
    if(c == '-') neg = true;
    else{
      num = num * 10 + (c - '0');
    }
  }
  return neg ? -num : num;
}

class Solution {
public:
    int calPoints(vector<string>& ops) {
      vector<int> scores;
      for(const string_view str : ops){
        if(str == "+"){
          int n = size(scores);
          scores.push_back(scores[n - 1] + scores[n - 2]);
        }else if(str == "D"){
          scores.push_back(scores.back() * 2);
        }else if(str == "C"){
          scores.pop_back();
        }else{
          scores.push_back(to_int(str));
        }
      }
      return accumulate(cbegin(scores), cend(scores), 0);
    }
};
