#include <unordered_map>
#include <list>
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


class RandomizedSet {
  unordered_map<int, int> mp;
  vector<int> lst;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (mp.find(val) != mp.end()) { return false; }
    mp[val] = size(lst);
    lst.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (mp.find(val) == mp.end()) { return false; }
    mp[lst.back()] = mp[val];
    swap(lst[mp[val]], lst.back());
    lst.pop_back();
    mp.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return lst[rand() % size(lst)];
  }
};

int main() {
  RandomizedSet st;
  cout << st.insert(0) << endl;
  cout << st.remove(0) << endl;
  cout << st.insert(-1) << endl;
  cout << st.remove(0) << endl;
  for (int i = 0; i < 10; i++) { cout << st.getRandom() << endl; }
}
