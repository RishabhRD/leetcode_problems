#include <list>
#include <unordered_map>
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
class ExamRoom {
  int n;
  unordered_map<int, list<int>::iterator> mp;
  list<int> seats;

public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    if (seats.empty()) {
      seats.push_back(0);
      mp[0] = seats.begin();
      return 0;
    }
    list<int>::iterator pos;
    int last = -1, dist, val;
    for (auto itr = begin(seats); itr != end(seats); itr++) {
      if (last == -1) {
        dist = *itr;
        pos = itr;
        val = 0;
      } else if ((*itr - last) / 2 > dist) {
        dist = (*itr - last) / 2;
        pos = itr;
        val = (*itr + last) / 2;
      }
      last = *itr;
    }
    if (n - 1 - seats.back() > dist) {
      pos = seats.end();
      val = n - 1;
    }
    mp[val] = seats.insert(pos, val);
    return val;
  }

  void leave(int p) { seats.erase(mp[p]); }
};
