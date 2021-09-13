#include <sstream>
#include <unordered_map>
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
  string frequencySort(string s) {
    unordered_map<char, int> mp;
    for(auto c : s){
      mp[c]++;
    }
    vector<pair<int, char>> f_vec;
    for(auto& [c, freq] : mp){
      f_vec.emplace_back(freq, c);
    }
    sort(begin(f_vec), end(f_vec), greater<pair<int, char>>{});
    stringstream stream;
    for(const auto& [freq, c] : f_vec){
      for(int i = 0; i < freq; i++){
        stream << c;
      }
    }
    return stream.str();
  }
};
