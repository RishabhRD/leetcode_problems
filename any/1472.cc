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

auto get_itr(int idx, vector<string>& vec){
  return begin(vec) + idx;
}

class BrowserHistory {
  vector<string> history;
  int cur_idx;

public:
  BrowserHistory(string homepage) : history{ homepage }, cur_idx{ 0 } {}

  void visit(string url) {
    auto itr = get_itr(cur_idx + 1, history);
    history.erase(itr, end(history));
    history.push_back(url);
    cur_idx++;
  }

  string back(int steps) {
    cur_idx = max(cur_idx - steps, 0);
    return history[cur_idx];
  }

  string forward(int steps) {
    cur_idx = min(cur_idx + steps, (int)size(history) - 1);
    return history[cur_idx];
  }
};
