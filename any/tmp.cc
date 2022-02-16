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
  int longestKSubstr(string s, int k) {
    int const n = s.size();
    int i = 0;
    int j = 0;
    int max_substring = 0;
    unordered_map<char, int> mp;
    while (j < n) {
      mp[s[j]]++;
      if (mp.size() < k) {
        j++;
        continue;
      }
      while (mp.size() > k) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) mp.erase(s[i]);
        i++;
      }
      max_substring = max(max_substring, j - i + 1);
      j++;
    }
    if (max_substring == 0) return -1;
    return max_substring;
  }
};

int main() {
  Solution sol;
  cout << sol.longestKSubstr("aabacbebebe", 3) << endl;
}
