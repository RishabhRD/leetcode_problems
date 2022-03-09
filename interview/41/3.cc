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

using Iter = vector<string>::const_iterator;

Iter next_line_range(Iter begin, Iter const end, int const max_width) {
  int cur_size = size(*begin);
  ++begin;
  for (; begin != end; ++begin) {
    int const new_size = cur_size + 1 + size(*begin);
    if (new_size > max_width)
      return begin;
    else
      cur_size = new_size;
  }
  return end;
}

vector<Iter> get_line_iters(Iter begin, Iter end, int maxWidth) {
  vector<Iter> lines_itr;
  while (begin != end) {
    begin = next_line_range(begin, end, maxWidth);
    lines_itr.push_back(begin);
  }
  return lines_itr;
}

auto range_size(Iter begin, Iter end) {
  return accumulate(begin, end, 0, [](auto old_size, string_view ele) {
    return old_size + size(ele);
  });
}

string make_string(Iter begin, Iter end, int maxWidth) {
  auto const space_needed = maxWidth - range_size(begin, end);
  auto const num_ele = distance(begin, end);
  int const num_space_blanks = num_ele - 1 == 0 ? 1 : num_ele - 1;
  auto even_space = space_needed / num_space_blanks;
  auto extra_space_ele = space_needed % num_space_blanks;
  stringstream os;
  os << *begin;
  ++begin;
  while (begin != end) {
    for (int i = 0; i < even_space; i++) os << ' ';
    if (extra_space_ele) {
      os << ' ';
      extra_space_ele--;
    }
    os << *begin;
    ++begin;
  }
  if (num_ele == 1) {
    for (int i = 0; i < space_needed; i++) os << ' ';
  }
  return os.str();
}

string make_last_string(Iter begin, Iter end, int maxWidth) {
  auto space_needed = maxWidth - range_size(begin, end);
  stringstream os;
  os << *begin;
  ++begin;
  for (; begin != end; ++begin) {
    os << ' ' << *begin;
    space_needed--;
  }
  for (int i = 0; i < space_needed; i++) os << ' ';
  return os.str();
}

auto convert_to_lines(Iter begin, vector<Iter> lines, int maxWidth) {
  vector<string> res;
  Iter last_one = lines.back();
  lines.pop_back();
  for (Iter cur : lines) {
    res.push_back(make_string(begin, cur, maxWidth));
    begin = cur;
  }
  res.push_back(make_last_string(begin, last_one, maxWidth));
  return res;
}

class Solution {
public:
  vector<string> fullJustify(vector<string> const &words, int maxWidth) {
    auto const line_itr = get_line_iters(begin(words), end(words), maxWidth);
    auto const to_lines =
      convert_to_lines(begin(words), move(line_itr), maxWidth);
    return to_lines;
  }
};

int main() {
  vector<string> const words{ "Science",
    "is",
    "what",
    "we",
    "understand",
    "well",
    "enough",
    "to",
    "explain",
    "to",
    "a",
    "computer.",
    "Art",
    "is",
    "everything",
    "else",
    "we",
    "do" };
  Solution sol;
  auto res = sol.fullJustify(words, 20);
  for (auto str : res) { cout << str << endl; }
}
