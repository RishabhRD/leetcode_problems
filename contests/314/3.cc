#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::string robotWithString(std::string s) {
    std::list<char> lst(std::begin(s), std::end(s));
    std::string store;
    std::string res;
    for (char c = 'a'; c <= 'z'; ++c) {
      auto begin = std::begin(lst);
      auto end = std::find(begin, std::end(lst), c);
      while (end != std::end(lst)) {
        std::for_each(begin, end, [&](auto ele) { store.push_back(ele); });
        end = std::next(end);
        res += c;
        lst.erase(begin, end);
        begin = std::begin(lst);
        end = std::find(begin, std::end(lst), c);
      }
    }
    while (not store.empty()) {
      res.push_back(store.back());
      store.pop_back();
    }
    return res;
  }
};
