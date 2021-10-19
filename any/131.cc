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

bool is_palindrome(string_view str, size_t begin, size_t end) {
  while (begin < end) {
    if (str[begin++] != str[end--]) return false;
  }
  return true;
}

void dfs(vector<vector<string>> &result,
  vector<string_view> &cur_result,
  size_t cur_idx,
  string_view str) {
  if (cur_idx == size(str)) {
    result.emplace_back(cbegin(cur_result), cend(cur_result));
    return;
  }
  for(size_t i = cur_idx; i < size(str); i++){
    if(is_palindrome(str, cur_idx, i)){
      cur_result.push_back(str.substr(cur_idx, i - cur_idx + 1));
      dfs(result, cur_result, i + 1, str);
      cur_result.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<string_view> cur_result;
    vector<vector<string>> result;
    dfs(result, cur_result, 0, s);
    return result;
  }
};
