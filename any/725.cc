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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

auto extract_group(ListNode *head, const int len) {
  if(len == 0) return head;
  for (int i = 0; i < len - 1; i++) {
    head = head->next;
  }
  const auto new_head = head->next;
  head->next = nullptr;
  return new_head;
}

auto size(const ListNode *head) {
  int sz = 0;
  for(auto cur_node = head; cur_node; cur_node = cur_node->next){
    sz++;
  }
  return sz;
}

auto get_list_group(ListNode* head, int k) {
  vector<ListNode*> roots;
  const auto len = size(head);
  const auto group_size = len / k;
  auto extra_holders = len % k;
  auto cur_node = head;
  for (int i = 0; i < k; i++, extra_holders--) {
    roots.push_back(cur_node);
    cur_node = extract_group(cur_node, group_size + (extra_holders > 0));
  }
  return roots;
}

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    return get_list_group(head, k);
  }
};
