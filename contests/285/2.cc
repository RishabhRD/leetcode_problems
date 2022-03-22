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

class Solution {
public:
  int countCollisions(string directions) {
    string right_left_collided{ directions.front() };
    int cnt = 0;
    for (auto c : string_view{ directions }.substr(1)) {
      if (c == 'L' and right_left_collided.back() == 'R') {
        cnt += 2;
        right_left_collided.pop_back();
        right_left_collided.push_back('S');
      } else {
        right_left_collided.push_back(c);
      }
    }
    string final_directions{ right_left_collided.front() };
    for (auto c : string_view{ right_left_collided }.substr(1)) {
      if (c == 'S') {
        while (final_directions.size() and final_directions.back() == 'R') {
          final_directions.pop_back();
          ++cnt;
        }
        final_directions.push_back('S');
      } else if (c == 'R') {
        final_directions.push_back(c);
      } else {
        if (final_directions.back() == 'S') {
          ++cnt;
        } else {
          final_directions.push_back(c);
        }
      }
    }
    return cnt;
  }
};

/* int main() { */
/*   Solution sol; */
/*   cout << sol.countCollisions("RLRSLL") << endl; */
/* } */
