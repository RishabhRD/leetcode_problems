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
};

template <typename T>
struct iterator_traits<value_iterator<T>> {
  typedef typename value_iterator<T>::iterator_category iterator_category;
  typedef typename value_iterator<T>::value_type value_type;
  typedef typename value_iterator<T>::difference_type difference_type;
};

class Solution {
 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long min_time = *min_element(begin(time), end(time));
    long long max_time = min_time * totalTrips;
    return *partition_point(
        value_iterator<long long>{1}, value_iterator<long long>{max_time + 1},
        [totalTrips, &time](auto cur_time) {
          return transform_reduce(begin(time), end(time), 0ll, std::plus<>{},
                                  [cur_time](auto ele) {
                                    return cur_time / ele;
                                  }) < totalTrips;
        });
  }
};
