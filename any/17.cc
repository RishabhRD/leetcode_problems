#include <map>
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

void comb(int cur_idx, map<int, vector<char>>& mp, string& cur_str, vector<string>& res, const string& given_str){
  if(cur_idx == size(given_str)){
    if(cur_str == "") return;
    res.push_back(cur_str);
    return;
  }
  for(auto c : mp[given_str[cur_idx] - '0']){
    cur_str += c;
    comb(cur_idx + 1, mp, cur_str, res, given_str);
    cur_str.pop_back();
  }
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    map<int, vector<char>> mp{
      { 2, { 'a', 'b', 'c' } },
      { 3, { 'd', 'e', 'f' } },
      { 4, { 'g', 'h', 'i' } },
      { 5, { 'j', 'k', 'l' } },
      { 6, { 'm', 'n', 'o' } },
      { 7, { 'p', 'q', 'r', 's' } },
      { 8, { 't', 'u', 'v' } },
      { 9, { 'w', 'x', 'y', 'z' } },
    };
    string cur_str;
    vector<string> res;
    comb(0, mp, cur_str, res, digits);
    return res;
  }
};
