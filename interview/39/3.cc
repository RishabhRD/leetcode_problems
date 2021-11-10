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

constexpr static double tolerable = 0.1;

bool judge(const vector<double> &cards) {
  if (size(cards) == 1) return abs(cards[0] - 24) <= tolerable;
  for (int i = 0; i < size(cards); i++) {
    for (int j = i + 1; j < size(cards); j++) {
      auto operate = [&](auto res) {
        vector<double> new_cards;
        for (int k = 0; k < size(cards); k++) {
          if (k == i or k == j) continue;
          new_cards.push_back(cards[k]);
        }
        new_cards.push_back(res);
        return new_cards;
      };
      double a = cards[i];
      double b = cards[j];
      vector<double> res{ a + b, a - b, a * b, b - a};
      if(b != 0) res.push_back(a / b);
      if(a != 0) res.push_back(b / a);
      for (auto r : res) {
        if (judge(operate(r))) return true;
      }
    }
  }
  return false;
}

class Solution {
public:
  bool judgePoint24(const vector<int> &cards) {
    vector<double> d_cards(begin(cards), end(cards));
    return judge(d_cards);
  }
};
