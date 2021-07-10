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

int findNumberOfLIS(vector<int> &nums) noexcept{
  const int size = nums.size();
  vector<int> len(size);
  vector<int> cnt(size);
  int max_len = 0;
  for(int i = 0; i < size; i++){
    for(int j = i - 1; j >= 0; j--){
      if(nums[i] > nums[j]){
        if(len[j] + 1 > len[i]){
          len[i] = len[j] + 1;
          cnt[i] = cnt[j];
        }else if(len[j] + 1 == len[i]){
          cnt[i] += cnt[j];
        }
      }
    }
    if(len[i] == 0){
      len[i] = 1;
      cnt[i] = 1;
    }
    max_len = max(max_len, len[i]);
  }
  int ans = 0;
  for(int i = 0; i < size; i++){
    if(len[i] == max_len){
      ans += cnt[i];
    }
  }
  return ans;
}

int main(int argc, const char** argv) {
  vector<int> nums = {1, 2, 4, 3, 5, 4, 7, 2};
  cout << nums << endl << endl;
  cout << findNumberOfLIS(nums) << endl;
    return 0;
}
