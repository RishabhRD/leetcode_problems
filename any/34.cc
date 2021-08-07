#include <algorithm>
#include <array>
#include <cmath>
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

int binary_search(const vector<int> &nums, int target) {
  int low = 0;
  int high = size(nums) - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

auto first_index_of(int low, int high, int target, const vector<int>& nums){
  while(low < high){
    int mid = (low + high) / 2;
    if(nums[mid] != target) low = mid + 1;
    else high = mid;
  }
  return low;
}

auto last_index_of(int low, int high, int target, const vector<int>& nums){
  while(low < high){
    int mid = ceil((low + high) / 2.0);
    if(nums[mid] != target) high = mid - 1;
    else low = mid;
  }
  return high;
}

vector<int> searchRange(const vector<int> &nums, int target) {
  auto index = binary_search(nums, target);
  if (index == -1)
    return {-1, -1};
  return {first_index_of(0, index, target, nums),
          last_index_of(index, size(nums) - 1, target, nums)};
}

int main(){
  cout << searchRange({5,7,7,8,8,10}, 8) << endl;
}
