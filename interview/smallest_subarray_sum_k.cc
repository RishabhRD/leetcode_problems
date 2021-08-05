#include <map>
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

int smallest_subarray_positive(const vector<int> &nums, const int k) {
  size_t low = 0;
  size_t high = 0;
  const auto n = size(nums);
  int sum = nums[0];
  size_t len = INT32_MAX;
  while (high < n - 1) {
    if(sum == k){
      len = min(len, high - low + 1);
      high++;
      sum += nums[high];
    }else if(sum > k){
      sum -= nums[low];
      low++;
    }else{
      high++;
      sum += nums[high];
    }
  }
  return len == INT32_MAX ? -1 : len;
}

int smallest_subarray(const vector<int>& nums, const int k){
  map<int, int> sums;
  auto sum_index = [&](int i){
    auto itr = sums.find(i);
    if(itr == sums.end()) return -1;
    return itr->second;
  };
  int cur_sum = 0;
  int len = INT32_MAX;
  for(int i = 0; i < size(nums); i++){
    cur_sum += nums[i];
    auto diff = k - cur_sum;
    if(diff == 0) len = min(len, i + 1);
    else{
      auto index = sum_index(cur_sum - k);
      if(index != -1){
        len = min(len, i - index);
      }
    }
    sums[cur_sum] = i;
  }
  return len == INT32_MAX ? -1 : len;
}

int main(){
  cout << smallest_subarray({1, 2, 4, 3, 2, 4, 1 }, 7) << endl;
}
