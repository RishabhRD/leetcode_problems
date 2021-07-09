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

int minPathSum(vector<vector<int>> &grid) {
  const int m = grid.size();
  const int n = grid[0].size();
  vector<vector<long long>> dp(2, vector<long long>(n, -1));
  auto is_in_range = [&](int i, int j){
    return i >= 0 and j >= 0 and i < m and j < n;
  };
  auto sol = [&](int i, int j){
    if(is_in_range(i, j)){
      return dp[i][j];
    }else{
      return (long long)INT32_MAX;
    }
  };
  dp[m - 1][n - 1] = grid[m - 1][n - 1];
  for(int i = m - 1; i >= 0; i--){
    for(int j = n - 1; j >= 0; j--){
      if(dp[i][j] == -1)
        dp[i][j] = grid[i][j] + min(sol(i + 1, j), sol(i, j + 1));
    }
  }
  /* printMatrix(dp); */
  return dp[0][0];
}

int main(int argc, const char** argv) {
  vector<vector<int>> grid{
    {1,3,1},{1,5,1},{4,2,1}
  };
  cout << minPathSum(grid) << endl;
    return 0;
}
