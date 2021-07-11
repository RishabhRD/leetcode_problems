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


template <typename T, typename Cont>
int total_paths(int x, int y, int moves_left, T&& is_out, Cont&& dp){
  constexpr static int mod  = 1e9 + 7;
  if(is_out(x, y)) return 1;
  else if(moves_left == 0) return 0;
  if(dp[x][y][moves_left] != -1) return dp[x][y][moves_left];
  int ans = 0;
  vector<pair<int, int>> arr = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  dp[x][y][moves_left] = 0;
  for(const auto& [incr_x, incr_y] : arr){
    dp[x][y][moves_left] = (dp[x][y][moves_left] + total_paths(x + incr_x, y +
          incr_y, moves_left - 1, is_out, dp) % mod) % mod;
  }
  return dp[x][y][moves_left];
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
  auto is_out = [&](int x, int y){
    return x < 0 or y < 0 or x >= m or y >= n;
  };
  vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
  return total_paths(startRow, startColumn, maxMove, is_out, dp);
}

int main(int argc, const char** argv) {
  cout << findPaths(1, 3, 3, 0, 1) << endl;
    return 0;
}
