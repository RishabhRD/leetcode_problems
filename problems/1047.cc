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
    string removeDuplicates(string s) {
      string str;
      for(auto c : s){
        bool found = false;
        while(not empty(str) and str.back() == c){
          str.pop_back();
          found = true;
        }
        if(found) continue;
        str += c;
      }
      return str;
    }
};
