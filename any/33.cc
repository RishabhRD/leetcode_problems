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

int bsearch(int low, int high, int target, const vector<int> &nums) {
  while (low <= high) {
    const auto mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int find_pivot(const vector<int>& nums){
  int low = 0;
  int high = size(nums) - 1;
  while(low < high){
    int mid = (low + high) / 2;
    if(nums[mid] > nums[high]) low = mid + 1;
    else high = mid;
  }
  return low;
}

int search(const vector<int> &nums, const int target) {
  const int pivot = find_pivot(nums);
  int ans = bsearch(0, pivot - 1, target, nums);
  if (ans != -1)
    return ans;
  ans = bsearch(pivot, size(nums) - 1, target, nums);
  if (ans != -1)
    return ans;
  return -1;
}

int main(int argc, const char** argv) {
  const vector<int> vec = {4,5,6,7,0,1,2};
  cout << find_pivot(vec) << endl;
  cout << search(vec, 5) << endl;
  return 0;
}
