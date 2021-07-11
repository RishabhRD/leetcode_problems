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

class Solution {
public:
  int arr_size;
  vector<vector<int>> dp;
  int ways_for_zero(int cur_pos, int steps_remaining) {
    constexpr static int mod = 1e9 + 7;
    if (steps_remaining == 0 and cur_pos == 0) {
      return 1;
    }
    if (cur_pos < 0 or cur_pos >= arr_size or steps_remaining == 0 or
        cur_pos > steps_remaining) {
      return 0;
    }
    if (dp[cur_pos][steps_remaining] != -1) {
      return dp[cur_pos][steps_remaining];
    }
    int sum = 0;
    sum = (sum + ways_for_zero(cur_pos + 1, steps_remaining - 1)) % mod;
    sum = (sum + ways_for_zero(cur_pos - 1, steps_remaining - 1)) % mod;
    sum = (sum + ways_for_zero(cur_pos, steps_remaining - 1)) % mod;
    dp[cur_pos][steps_remaining] = sum;
    return sum;
  }

  int numWays(int steps, int arrLen) {
    dp.resize(steps / 2 + 1, vector<int>(steps + 1, -1));
    arr_size = arrLen;
    return ways_for_zero(0, steps);
  }
};
