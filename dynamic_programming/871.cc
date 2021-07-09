#include <queue>
#include <unordered_map>
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

// Here DP is max distance we can cover if we stop for j out of i stops
int minRefuelStops(const int target, const int startFuel, const vector<vector<int>> &stations) noexcept {
  const int size = stations.size();
  using lint = long long;
  vector<vector<lint>> dp(size + 1, vector<lint>(size + 1));
  for(int i = 0; i <= size; i++){
    dp[i][0] = startFuel;
  }

  for(int i = 1; i <= size; i++){
    for(int j = 1; j <= size; j++){
      dp[i][j] = dp[i - 1][j];
      if(dp[i - 1][j - 1] >= stations[i - 1][0]){
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1]);
      }
    }
  }
  for(int j = 0; j <= size; j++){
    if(dp[size][j] >= target){
      return j;
    }
  }
  return -1;
}

int minRefuelStops(const int target, const int startFuel, const vector<vector<int>> &stations) noexcept {
  const auto size = stations.size();
  auto dist = startFuel;
  auto num_filled = 0;
  auto cur_idx = 0;
  priority_queue<int> pq;
  while(true){
    while(cur_idx < size and stations[cur_idx][0] <= dist){
      pq.push(stations[cur_idx][1]);
      cur_idx++;
    }
    if(dist >= target) return num_filled;
    if(pq.empty()) return -1;
    dist += pq.top();
    pq.pop();
    num_filled++;
  }
  return -1;
}

int main(int argc, const char** argv) {
  cout << minRefuelStops(13, 1, {{10, 100}}) << endl;
    return 0;
}
