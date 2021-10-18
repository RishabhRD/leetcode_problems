#include <set>
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
  string largestNumber(vector<int> &nums) {
    vector<string> str_vec;
    transform(cbegin(nums), cend(nums), back_inserter(str_vec), [](int num) {
      return to_string(num);
    });
    sort(begin(str_vec), end(str_vec), [](const string &s1, const string &s2) {
      return s1 + s2 > s2 + s1;
    });
    return str_vec[0][0] == '0'
             ? "0"
             : accumulate(cbegin(str_vec), cend(str_vec), ""s);
  }
};
