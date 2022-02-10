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
  string minWindow(string str, string t) {
    string_view s{ str };
    int const m = size(t);
    int const n = size(s);
    auto const mp = [&t] {
      array<int, 128> mp{ 0 };
      for (auto c : t) mp[c]++;
      return mp;
    }();
    array<int, 128> window{ 0 };
    int slow = 0;
    int total_ele = 0;
    int min_len = INT32_MAX;
    string_view res;
    int cnt = 0;
    for (int fast = 0; fast < n; fast++) {
      auto const c = s[fast];
      if (mp[c]) {
        window[c]++;
        if (window[c] <= mp[c]) { cnt++; }
      }
      if (cnt >= m) {
        while (true) {
          auto const slow_c = s[slow];
          if (!mp[slow_c])
            slow++;
          else if (mp[slow_c] < window[slow_c]) {
            slow++;
            window[slow_c]--;
          } else
            break;
        }
        if (min_len > (fast - slow + 1)) {
          min_len = fast - slow + 1;
          res = s.substr(slow, min_len);
        }
      }
    }
    return string{ res };
  }
};

int main() {
  Solution sol;
  cout << sol.minWindow("adobecodebanc", "abc") << endl;
}
