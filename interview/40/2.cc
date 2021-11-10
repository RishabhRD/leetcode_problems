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
  string getHint(string secret, string guess) {
    int a = 0;
    vector<int> s_vec(10);
    vector<int> g_vec(10);
    for (int i = 0; i < size(secret); i++) {
      if (secret[i] == guess[i])
        a++;
      else {
        s_vec[secret[i] - '0']++;
        g_vec[guess[i] - '0']++;
      }
    }
    int b = 0;
    for (int i = 0; i < 10; i++) { b += min(s_vec[i], g_vec[i]); }
    return to_string(a) + 'A' + to_string(b) + 'B';
  }
};
