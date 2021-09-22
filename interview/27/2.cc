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
  auto smallestSubsequence(string s) {
    vector<int> cnt(26);
    vector<bool> used(26);
    for(auto c : s) cnt[c - 'a']++;
    string str;
    for (auto c : s) {
      cnt[c - 'a']--;
      if (used[c - 'a']) continue;
      used[c - 'a'] = true;
      while (size(str) > 0 and cnt[str.back() - 'a'] > 0 and str.back() > c) {
        used[str.back() - 'a'] = false;
        str.pop_back();
      }
      str.push_back(c);
    }
    return str;
  }
};

int main() {
  Solution sol;
  cout << sol.smallestSubsequence("cdadabcc") << endl;
}
