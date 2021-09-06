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
  int uniqueLetterString(string s) {
    vector index(26, vector<int>(2, -1));
    const int n = size(s);
    const static int mod = pow(10, 9) + 7;
    int res = 0;
    for(int i = 0; i < n; i++){
      int c = s[i] - 'A';
      res = (res +  (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
      index[c][0] = index[c][1];
      index[c][1] = i;
    }
    for(int c = 0; c < 26; c++){
      res = (res +  (n - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
    }
    return res;
  }
};

int main(){
  Solution sol;
  cout << sol.uniqueLetterString("ABC") << endl;
}
