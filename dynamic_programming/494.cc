#include <cmath>
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

int fs(vector<int> nums, int S){
  int sum = 0;
  for (auto n : nums) sum += n;
  if ((sum + S) % 2 == 1 || S > sum || S < -sum) return 0;
  int newS = (sum + S) / 2;
  vector<int> dp(newS + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = newS; j >= nums[i]; --j) {
      dp[j] += dp[j - nums[i]];
    }
  }
  return dp[newS];
}

int findTargetSumWays(vector<int> &nums, int target) noexcept{
  const auto sum = accumulate(cbegin(nums), cend(nums), 0);
  const auto size = nums.size();
  if ((sum + target) % 2 or target > sum or target < -sum)
    return 0;
  target = (sum + target) / 2;
  using lint = long long;
  vector<int> dp(target + 1);
  dp[0] = 1;
  for (int num : nums) {
    for (int i = target; i >= 0; i--) {
      if (i - num >= 0) {
        dp[i] += dp[i - num];
      }
    }
  }
  return dp[target] ;
}

int main(int argc, const char **argv) {
  vector<int> vec = {0, 1};
  int target = 1;
  cout << findTargetSumWays(vec, target) << endl;
  return 0;
}
