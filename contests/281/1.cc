#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
struct value_iterator {
  T val;

  using value_type = T;
  using difference_type = size_t;
  using iterator_category = std::random_access_iterator_tag;

  T operator*() { return val; }

  value_iterator& operator++() {
    ++val;
    return *this;
  }

  value_iterator operator+(size_t n) { return val + n; }

  size_t operator-(value_iterator i) { return val - i.val; }

  value_iterator operator--() {
    --val;
    return *this;
  }

  void operator+=(size_t n) { val += n; }

  bool operator!=(value_iterator v) { return val != v.val; }
};

template <typename T>
struct iterator_traits<value_iterator<T>> {
  typedef typename value_iterator<T>::iterator_category iterator_category;
  typedef typename value_iterator<T>::value_type value_type;
  typedef typename value_iterator<T>::difference_type difference_type;
};

int digit_sum(int e) {
  int sum = 0;
  while (e) {
    int rem = e % 10;
    sum += rem;
    e = e / 10;
  }
  return sum;
}

class Solution {
 public:
  int countEven(int num) {
    return count_if(value_iterator<int>{1}, value_iterator<int>{num + 1},
                    [](auto e) { return digit_sum(e) % 2 == 0; });
  }
};
