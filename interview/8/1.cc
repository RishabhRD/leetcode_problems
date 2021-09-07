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
  vector<string> findOcurrences(string text, string first, string second) {
    stringstream is(text);
    string word, prev, prev2;
    vector<string> ans;
    while(is >> word){
      if(prev2 == first and prev == second){
        ans.push_back(word);
      }
      prev2 = prev;
      prev = word;
    }
    return ans;
  }
};
