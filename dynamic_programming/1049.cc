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

int lastStoneWeightII(const vector<int> &stones) {
  const int sum = accumulate(cbegin(stones), cend(stones), 0);
  const int n = stones.size();
  using lint = long long;
  vector<vector<bool>> dp(sum / 2 + 1, vector<bool>(n + 1));
  for(int i = 0; i < n + 1; i++){
    dp[0][i] = true;
  }
  for(int i = 1; i <= sum / 2; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = dp[i][j - 1];
      if(i - stones[j - 1] >= 0){
        dp[i][j] = dp[i][j] or dp[i - stones[j - 1]][j - 1];
      }
    }
  }
  auto func = [&](int i){
    return sum - 2 * i;
  };
  int min_ans = INT32_MAX;
  for(int i = 0; i <= sum / 2; i++){
    if(dp[i][n]){
      min_ans = min(min_ans, func(i));
    }
  }
  return min_ans;
}
