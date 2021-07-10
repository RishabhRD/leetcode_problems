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

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  const int m = obstacleGrid.size();
  const int n = obstacleGrid[0].size();
  using lint = long long;
  vector<vector<lint>> dp(m, vector<lint>(n));
  dp[m - 1][n - 1] = 1;
  auto is_in_range = [&](int i, int j){
    return i >= 0 and j >= 0 and i < m and j < n;
  };
  for(int i = m - 1; i >= 0; i--){
    for(int j = n - 1; j >= 0; j--){
      if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
      else{
        if(is_in_range(i + 1, j)){
          dp[i][j] += dp[i + 1][j];
        }
        if(is_in_range(i, j + 1)){
          dp[i][j] += dp[i][j + 1];
        }
      }
    }
  }
  return dp[0][0];
}
