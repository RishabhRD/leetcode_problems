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

string longestPalindrome(const string& s) noexcept{
  const int n = s.size();
  vector<vector<bool>> dp(n, vector<bool>(n));
  auto length = [](int low, int high){
    return high - low + 1;
  };
  int low = 0;
  int high = 0;
  for(int i = 0; i < n; i++){
    dp[i][i] = true;
  }
  for(int i = 0; i < n - 1; i++){
    if(s[i] == s[i + 1]){
      dp[i][i + 1] = true;
      if(length(i, i + 1) > length(low, high)){
        low = i;
        high = i + 1;
      }
    }
  }
  for(int len = 3; len <= n; len++){
    for(int i = 0; i <= n - len; i++){
      int j = i + len - 1;
      if(s[i] == s[j]){
        dp[i][j] = dp[i + 1][j - 1];
      }
      if(dp[i][j] == true){
        if(length(low, high) < length(i, j)){
          low = i;
          high = j;
        }
      }
    }
  }
  return s.substr(low, length(low, high));
}

int main(int argc, const char** argv) {
  cout << longestPalindrome("cbbd") << endl;
    return 0;
}
