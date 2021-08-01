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

template <typename Range>
int bsearch(const Range& range, int target){
  int low = 0;
  int high = size(range) - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(range[mid] == target){
      return mid;
    }else if(range[mid] > target){
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}

int first_index_of(vector<int>& nums, int low, int high, int target){
  while(low < high){
    int mid = (low + high) / 2;
    if(nums[mid] != target){
      low = mid + 1;
    }else{
      high = mid;
    }
  }
  return high;
}

int last_index_of(vector<int>& nums, int low, int high, int target){
  while(low < high){
    int mid = ceil((low + high) / 2.0);
    if(nums[mid] != target){
      high = mid - 1;
    }else{
      low = mid;
    }
  }
  return low;
}

vector<int> searchRange(vector<int> &nums, int target) {
  const int target_index = bsearch(nums, target);
  if(target_index == -1) return {-1, -1};
  return { first_index_of(nums, 0, target_index, target),
    last_index_of(nums, target_index, size(nums) - 1, target)
  };
}

int main(int argc, const char** argv) {
  vector vec{5,7,7,8,8,10};
  /* cout << bsearch(vec, 8) << endl; */
  /* cout << first_index_of(vec, 0, 4, 8) << endl; */
  cout << last_index_of(vec, 4, 5, 8) << endl;
   return 0;
}
