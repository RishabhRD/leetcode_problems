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

int min_dist(const string& s1, const string& s2, int i, int j, int m, int n, vector<vector<int>>& dp){
  if(i == m and j == n) return 0;
  if(i == m){
    return n - j;
  }
  if(j == n){
    return m - i;
  }
  if(dp[i][j] != -1) return dp[i][j];
  if(s1[i] == s2[j]){
    dp[i][j] = min_dist(s1, s2, i + 1, j + 1, m, n, dp);
  }else{
    dp[i][j] = min({
        1 + min_dist(s1, s2, i + 1, j + 1, m, n, dp),
        1 + min_dist(s1, s2, i, j + 1, m, n, dp),
        1 + min_dist(s1, s2, i + 1, j, m , n, dp)
            });
  }
  return dp[i][j];
}

int minDistance(string word1, string word2) noexcept {
  const int m = word1.size();
  const int n = word2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1));
  for(int i = 1; i <= m; i++){
    dp[i][0] = i;
  }
  for(int i = 1; i <= n; i++){
    dp[0][i] = i;
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(word1[i - 1] == word2[j - 1]){
        dp[i][j] = dp[i - 1][j - 1];
      }else{
        dp[i][j] = 1 + min({
            dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]
            });
      }
    }
  }
  return dp[m][n];
}

int main() {
}
