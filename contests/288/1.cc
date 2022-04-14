#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestInteger(int num) {
    string const str_num = to_string(num);
    vector<char> odd_digits;
    vector<char> even_digits;
    copy_if(begin(str_num), end(str_num), back_inserter(odd_digits),
            [](auto c) { return (c - '0') % 2 == 1; });
    copy_if(begin(str_num), end(str_num), back_inserter(even_digits),
            [](auto c) { return (c - '0') % 2 == 0; });

    sort(begin(odd_digits), end(odd_digits), std::greater<>{});
    sort(begin(even_digits), end(even_digits), std::greater<>{});
    auto even_itr = cbegin(even_digits);
    auto odd_itr = cbegin(odd_digits);
    auto cur_itr = cbegin(str_num);
    string str;
    while (cur_itr != cend(str_num)) {
      if (*cur_itr % 2 == 0) {
        str += *even_itr;
        ++even_itr;
      } else {
        str += *odd_itr;
        ++odd_itr;
      }
      ++cur_itr;
    }
    return stoi(str);
  }
};
