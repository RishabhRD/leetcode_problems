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

int maxCoins(vector<int> &nums) noexcept{
  const int n = nums.size();
  auto at = [&](int i){
    if(i < 0 or i >= nums.size()) return 1;
    return nums[i];
  };
  vector<vector<int>> dp(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    dp[i][i] = at(i) * at(i - 1) * at(i + 1);
  }
  for(int len = 2; len <= n; len++){
    for(int i = 0; i <= n - len; i++){
      int j = i + len - 1;
      for(int k = i ; k <= j; k++){
        int cur = at(k) * at(i - 1) * at(j + 1);
        if(k - 1 >= i){
          cur += dp[i][k - 1];
        }
        if(k + 1 <= j){
          cur += dp[k + 1][j];
        }
        dp[i][j] = max(dp[i][j], cur);
      }
    }
  }
  return dp[0][n - 1];
}

int main(int argc, const char** argv) {
  vector vec = {3, 1, 5, 8};
  cout << maxCoins(vec) << endl;
    return 0;
}
