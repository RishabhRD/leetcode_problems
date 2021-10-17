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

int atmost(string_view s, int k, char c){
  int i = 0, j;
  const int n = size(s);
  for(j = 0; j < n; j++){
    if(s[j] == c) k--;
    if(k < 0 and s[i++] == c) k++;
  }
  return j - i;
}

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
      return max(atmost(answerKey, k, 'T'), atmost(answerKey, k, 'F'));
    }
};
