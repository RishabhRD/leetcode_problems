#include <set>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

auto concat_compare(string const &str1, string const &str2) {
  auto const s1 = str1 + str2;
  auto const s2 = str2 + str1;
  return s1 > s2;
}

auto flatten(vector<string> const &strs) {
  ostringstream stream;
  copy(begin(strs), end(strs), ostream_iterator<string>(stream));
  return stream.str();
}

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> numbers;
    transform(begin(nums), end(nums), back_inserter(numbers), [](auto num) {
      return to_string(num);
    });
    sort(begin(numbers), end(numbers), concat_compare);
    auto str = flatten(numbers);
    if (str[0] == '0') return "0";
    return str;
  }
};
