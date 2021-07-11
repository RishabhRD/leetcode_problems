#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
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


int num_ways(int prev, int ways_left, vector<vector<int>>& dp) noexcept{
  constexpr static int mod = 1e9 + 7;
  static vector<vector<int>> mapping = {
    {1},
    {0, 2}, 
    {0, 1, 3, 4},
    {2, 4}, 
    {0}
  };
  if(ways_left == 0) return 1;
  if(dp[prev][ways_left] != -1){
    return dp[prev][ways_left];
  }
  int sum = 0;
  for(int cur : mapping[prev]){
    sum = (sum + num_ways(cur, ways_left - 1, dp)) % mod;
  }
  dp[prev][ways_left] = sum;
  return sum;
}

int countVowelPermutation(int n) noexcept{
  constexpr static int mod = 1e9 + 7;
  vector<vector<int>> mp(5, vector<int>(n + 1, -1));
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum = (sum + num_ways(i, n - 1, mp)) % mod;
  }
  return sum;
}

int main(int argc, const char **argv) {
  cout << countVowelPermutation(2) << endl;
  return 0;
}
