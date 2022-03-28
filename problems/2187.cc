#include <algorithm>
#include <numeric>
#include <ranges>
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
  long long minimumTime(vector<int>& one_trip_time, int total_trips) {
    long long min_time = *min_element(begin(one_trip_time), end(one_trip_time));
    long long max_time = min_time * total_trips;
    return *partition_point(
        value_iterator<long long>{1}, value_iterator<long long>{max_time + 1},
        [total_trips, &one_trip_time](auto cur_time) {
          return transform_reduce(begin(one_trip_time), end(one_trip_time), 0ll,
                                  std::plus<>{}, [cur_time](auto ele) {
                                    return cur_time / ele;
                                  }) < total_trips;
        });
  }
};

// ranges solution

auto minimumTime(vector<int> const& one_trip_time, int const total_trips) {
  long long const min_one_trip_time = *ranges::min_element(one_trip_time);
  auto const max_time_req = min_one_trip_time * total_trips;
  auto possible_complete_times = views::iota(1ll, max_time_req + 1);

  return *ranges::partition_point(possible_complete_times, [&](auto cur_time) {
    return one_trip_time                         //
           | views::transform(divide(cur_time))  //
           | ranges::fold(0ll);
  });
}
