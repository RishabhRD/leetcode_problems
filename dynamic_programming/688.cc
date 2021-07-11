#include <algorithm>
#include <array>
#include <cmath>
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

template <typename T, typename Cont>
double knight_moves(int x, int y, int moves_left, T &&is_out, Cont &&dp) {
  if (is_out(x, y)) {
    return 0;
  }
  if (moves_left == 0) {
    return 1;
  }
  if (dp[x][y][moves_left] != -1) {
    return dp[x][y][moves_left];
  }
  vector<pair<int, int>> moves{{-1, -2}, {1, -2}, {-2, -1}, {2, -1},
                               {-2, 1},  {2, 1},  {-1, 2},  {1, 2}};

  dp[x][y][moves_left] = 0;
  for (const auto &[incr_x, incr_y] : moves) {
    dp[x][y][moves_left] += 0.125 * knight_moves(x + incr_x, y + incr_y,
                                                 moves_left - 1, is_out, dp);
  }
  return dp[x][y][moves_left];
}

double knightProbability(int n, int k, int row, int column) {
  vector<vector<vector<double>>> dp(
      n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
  auto is_out = [&](int x, int y) {
    return x < 0 or y < 0 or x >= n or y >= n;
  };
  return knight_moves(row, column, k, is_out, dp);
}

int main(int argc, const char **argv) {
  cout << knightProbability(3, 2, 0, 0) << endl;
  return 0;
}
