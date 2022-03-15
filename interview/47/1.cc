#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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

template<typename Iter> string concat(Iter begin, Iter end) {
  std::ostringstream os;
  os << *begin;
  while (++begin != end) { os << ' ' << *begin; }
  return os.str();
}

class Solution {
public:
  string reverseWords(string s) {
    stringstream in{ s };
    vector<string> res_vec;
    string res;
    while (in >> res) { res_vec.push_back(res); }
    reverse(begin(res_vec), end(res_vec));
    return concat(begin(res_vec), end(res_vec));
  }
};
