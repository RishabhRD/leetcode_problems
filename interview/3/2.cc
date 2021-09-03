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

template <typename First, typename Second>
std::ostream& operator<<(std::ostream& os, const pair<First, Second>& pr){
  os << "(" << pr.first << ", " << pr.second << ")";
  return os;
}

template <typename Container>
void print(const Container& cont){
  for(auto x : cont){
    cout << x << " ";
  }
  cout << endl;
}

auto get_compressed_str(const string &s) {
  char prev_char = 0;
  vector<pair<char, int>> ret;
  for (auto c : s) {
    if (prev_char == c) {
      ret.back().second++;
    } else {
      ret.emplace_back(c, 1);
    }
    prev_char = c;
  }
  return ret;
}

bool is_possible(const vector<pair<char, int>> &to_check,
  const vector<pair<char, int>> &from_check) {
  if (size(to_check) != size(from_check)) return false;
  const int n = size(to_check);
  for (int i = 0; i < n; i++) {
    if (to_check[i].first != from_check[i].first) {
      return false;
    } else {
      if (from_check[i].second == 1 and to_check[i].second == 2) {
        return false;
      }else if(from_check[i].second > to_check[i].second){
        return false;
      }
    }
  }
  return true;
}

class Solution {
public:
  int expressiveWords(string s, vector<string> &words) {
    auto new_str = get_compressed_str(s);
    vector<vector<pair<char, int>>> new_vec;
    transform(
      cbegin(words), cend(words), back_inserter(new_vec), get_compressed_str);
    return count_if(cbegin(new_vec), cend(new_vec), [&](const auto &from_str) {
      return is_possible(new_str, from_str);
    });
  }
};

int main(){
  Solution sol;
  vector<string> words = {"hello", "hi", "helo"};
  string str = "heeellooo";
  cout << sol.expressiveWords(str, words) << endl;
}
