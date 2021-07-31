#include <queue>
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

template <typename T>
concept is_container = requires(T a) {
  a.begin();
  a.end();
};

template <is_container T>
requires(!std::same_as<T, std::string>) std::ostream &
operator<<(std::ostream &os, const T &cont) {
  os << '{';
  for (const auto &x : cont) {
    os << x;
    os << ' ';
  }
  os << '}';
  return os;
}

void printMatrix(const is_container auto &cont) {
  for (const auto &x : cont) {
    cout << x;
    cout << '\n';
  }
}

template <typename T, std::size_t... Is>
constexpr std::array<T, sizeof...(Is)>
create_array(T value, std::index_sequence<Is...>) {
  return {{(static_cast<void>(Is), value)...}};
}

template <std::size_t N, typename T>
constexpr std::array<T, N> create_array(const T &value) {
  return create_array(value, std::make_index_sequence<N>());
}
template <typename T> constexpr auto accessor(T &t) {
  return [&](int i) -> typename T::reference { return t.at(i); };
}

template <typename T> constexpr auto accessor(const T &t) {
  return [&](int i) { return t.at(i); };
}

template <typename T> constexpr auto const_accessor(T &t) {
  return [&](int i) { return t.at(i); };
}

template <typename T> constexpr auto matrix_accessor(T &t) {
  return [&](int i, int j) ->
         typename T::value_type::reference { return t.at(i).at(j); };
}

template <typename T> constexpr auto matrix_accessor(const T &t) {
  return [&](int i, int j) { return t.at(i).at(j); };
}

template <typename T> constexpr auto const_matrix_accessor(T &t) {
  return [&](int i, int j) { return t.at(i).at(j); };
}

template <typename T> using lmt = std::numeric_limits<T>;

template <typename T, std::size_t N>
constexpr std::size_t array_size(const T (&)[N]) noexcept {
  return N;
}

class MedianFinder {
  priority_queue<int> first_q;
  priority_queue<int, vector<int>, greater<int>> second_q;
public:
  MedianFinder() {}

  void addNum(int num) {
    if(first_q.empty() or first_q.top() > num){
      first_q.push(num);
    }else{
      second_q.push(num);
    }

    if(first_q.size() > second_q.size() + 1){
      second_q.push(first_q.top());
      first_q.pop();
    }else if(first_q.size() + 1 < second_q.size()){
      first_q.push(second_q.top());
      second_q.pop();
    }
  }

  double findMedian() {
    if(first_q.size() == second_q.size()){
      if(first_q.size() == 0) return 0;
      return (first_q.top() + second_q.top()) / 2.0;
    }else{
      if(first_q.size() > second_q.size()) return first_q.top();
      else return second_q.top();
    }
  }
};

int main(int argc, const char** argv) {
  MedianFinder finder;
  finder.addNum(3);
  finder.addNum(4);
  cout << finder.findMedian() << endl;
    return 0;
}
