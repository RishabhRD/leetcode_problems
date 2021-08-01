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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <typename Func> void morris(TreeNode *root, Func &&func) {
  struct TreeNode *current, *pre;

  if (root == nullptr)
    return;

  current = root;
  while (current != nullptr) {

    if (current->left == nullptr) {
      func(current->val);
      current = current->right;
    } else {
      pre = current->left;
      while (pre->right != nullptr && pre->right != current)
        pre = pre->right;
      if (pre->right == nullptr) {
        pre->right = current;
        current = current->left;
      } else {
        pre->right = nullptr;
        func(current->val);
        current = current->right;
      }
    }
  }
}


class Solution {
public:
  bool isValidBST(TreeNode *root) {
    int pre = INT32_MIN;
    bool first = true;
    bool is_incr = true;
    auto is_increasing = [&](int val){
      if(first){
        pre = val;
        first = false;
        return;
      }
      if(val <= pre){
        is_incr = false;
      }
      pre = val;
    };
    morris(root, is_increasing);
    return is_incr;
  }
};

int main(int argc, const char** argv) {
  TreeNode tr5(5);
  TreeNode tr1(1);
  TreeNode tr4(4);
  TreeNode tr3(3);
  TreeNode tr6(6);
  tr5.left = &tr1;
  tr5.right = &tr4;
  tr4.left = &tr3;
  tr4.right = &tr6;
    return 0;
}
