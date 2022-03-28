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
    vector<string> buildArray(const vector<int>& target, int n) {
      auto next = [cur = 1]() mutable{
        return cur++;
      };
      vector<string> res;
      for(auto i : target){
        while(i != next()){
          res.push_back("Push");
          res.push_back("Pop");
        }
        res.push_back("Push");
      }
      return res;
    }
};
