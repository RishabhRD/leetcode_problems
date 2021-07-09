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

int findMaxForm_high_space(vector<string> &strs, int m, int n) {
  vector<int> num_zeroes;
  transform(cbegin(strs), cend(strs), back_inserter(num_zeroes),
            [](const auto &str) { return count(cbegin(str), cend(str), '0'); });
  vector<int> num_ones;
  transform(cbegin(strs), cend(strs), back_inserter(num_ones),
            [](const auto &str) { return count(cbegin(str), cend(str), '1'); });
  const int size = strs.size();
  using lint = long long;
  vector<vector<vector<lint>>> dp(size + 1, vector<vector<lint>>(m + 1, vector<lint>(n + 1)));
  for(int i = 1; i <= size; i++){
    for(int j = 0; j <= m; j++){
      for(int k = 0; k <= n; k++){
        dp[i][j][k] = dp[i - 1][j][k];
        const int zero = num_zeroes[i - 1];
        const int one = num_ones[i - 1];
        if(j - zero >= 0 and k - one >= 0){
          dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - zero][k - one]);
        }
      }
    }
  }
  /* cout << dp << endl; */
  return dp[size][m][n];
}

int findMaxForm(vector<string> &strs, int m, int n) noexcept {
  using lint = long long;
  vector<vector<lint>> dp(vector<vector<lint>>(m + 1, vector<lint>(n + 1)));
  for(const auto& str : strs){
    const int num_zeroes = count(cbegin(str), cend(str), '0');
    const int num_ones = str.size() - num_zeroes;
    for(int j = m; j >= num_zeroes; j--){
      for(int k = n; k >= num_ones; k--){
        dp[j][k] = max(dp[j][k], 1 + dp[j - num_zeroes][k - num_ones]);
      }
    }
  }
  return dp[m][n];
}

int main(int argc, const char** argv) {
  vector<string> strs = {"10","0001","111001","1","0"};
  int m = 5, n = 3;
  cout << findMaxForm(strs, m, n) << endl;
    return 0;
}
