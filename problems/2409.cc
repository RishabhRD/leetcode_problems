#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int to_int(char a, char b) {
  int sum = 0;
  sum = sum * 10 + (a - '0');
  sum = sum * 10 + (b - '0');
  return sum;
}

struct date_t {
  int day;
  int month;
};

auto to_date(std::string_view str) {
  return date_t{to_int(str[3], str[4]), to_int(str[0], str[1]) - 1};
}

auto to_int(date_t date) {
  constexpr static std::array<int, 12> dates = {31, 28, 31, 30, 31, 30,
                                                31, 31, 30, 31, 30, 31};

  int ans = 0;
  for (int i = 0; i < date.month; ++i) {
    ans += dates[i];
  }
  ans += date.day;
  return ans;
}

int collide(int a, int b, int c, int d) {
  if (c < a) return collide(c, d, a, b);
  if (b >= d) {
    return d - c + 1;
  } else if (b >= c) {
    return b - c + 1;
  } else {
    return 0;
  }
}

class Solution {
 public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    auto a = to_int(to_date(arriveAlice));
    auto b = to_int(to_date(leaveAlice));
    auto c = to_int(to_date(arriveBob));
    auto d = to_int(to_date(leaveBob));
    return collide(a, b, c, d);
  }
};
