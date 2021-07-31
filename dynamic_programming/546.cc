#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

template <typename T> concept is_container = requires(T a) {
  a.begin();
  a.end();
};

template <is_container T>requires (!std::same_as<T, std::string>)
std::ostream &operator<<(std::ostream &os, const T &cont) {
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
template <typename T>
constexpr auto accessor(T& t){
  return [&](int i) -> typename T::reference{
    return t.at(i);
  };
}

template <typename T>
constexpr auto accessor(const T& t){
  return [&](int i){
    return t.at(i);
  };
}

template <typename T>
constexpr auto const_accessor(T& t){
  return [&](int i){
    return t.at(i);
  };
}

template <typename T>
constexpr auto matrix_accessor(T& t){
  return [&](int i, int j) -> typename T::value_type::reference{
    return t.at(i).at(j);
  };
}

template <typename T>
constexpr auto matrix_accessor(const T& t){
  return [&](int i, int j) {
    return t.at(i).at(j);
  };
}

template <typename T>
constexpr auto const_matrix_accessor(T& t){
  return [&](int i, int j) {
    return t.at(i).at(j);
  };
}

template <typename T>
using lmt = std::numeric_limits<T>;

template <typename T, std::size_t N>
constexpr std::size_t array_size(const T (&)[N]) noexcept{
  return N;
}

int removeBoxes(vector<int>& boxes) {
  const int n = boxes.size();
  vector<vector<bool>> same(n, vector<bool>(n, true));
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      for(int k = i + 1; k <= j; k++){
        if(boxes[k] != boxes[k - 1]){
          same[i][j] = false;
          break;
        }
      }
    }
  }

  vector<vector<int>> dp(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    dp[i][i] = 1;
  }

  for(int len = 2; len <= n; len++){
    for(int i = 0; i <= n - len; i++){
      int j = i + len - 1;
      for(int k1 = i; k1 <= j; k1++){
        for(int k2 = k1; k2 <= j; k2++){
          if(not same[k1][k2]){
            break;
          }
          int cur = (k2 - k1 + 1) * (k2 - k1 + 1);
          if(k1 - 1 >= i){
            cur += dp[i][k1 - 1];
          }
          if(k2 + 1 <= j){
            cur += dp[k2 + 1][j];
          }
          dp[i][j] = max(dp[i][j], cur);
        }
      }
    }
  }
  printMatrix(dp);
  return dp[0][n - 1];
}

int main(int argc, const char** argv) {
  int num= 4;
  num = 45 > 23 ? : 3;
  cout << num << endl;
    return 0;
}
