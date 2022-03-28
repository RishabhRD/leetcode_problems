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

map<char, string> const l_map{
  { '2', "abc" },
  { '3', "def" },
  { '4', "ghi" },
  { '5', "jkl" },
  { '6', "mno" },
  { '7', "pqrs" },
  { '8', "tuv" },
  { '9', "wxyz" },
};

void comb(int const cur_idx,
  string_view const digits,
  vector<string> &res,
  string &cur_str) {
  if (cur_idx == size(digits)) {
    res.push_back(cur_str);
    return;
  }
  for (auto c : l_map.at(digits[cur_idx])) {
    cur_str += c;
    comb(cur_idx + 1, digits, res, cur_str);
    cur_str.pop_back();
  }
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    string cur_str;
    vector<string> res;
    if (digits == "") return res;
    comb(0, digits, res, cur_str);
    return res;
  }
};
