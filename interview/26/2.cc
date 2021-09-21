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

class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {}

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    return Iterator(*this).next();
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    return Iterator::next();
  }

  bool hasNext() const {
    return Iterator::hasNext();
  }
};

