#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;


class Trie {
  struct trie_node {
    bool is_leaf;
    array<trie_node *, 128> children{ nullptr };
  };

  trie_node *head;

public:
  Trie() : head{ new trie_node{ false } } {}

  void insert(string word) {
    auto cur = head;
    for (auto c : word) {
      if (cur->children[c] == nullptr) {
        cur->children[c] = new trie_node{ false };
      }
      cur = cur->children[c];
    }
    cur->is_leaf = true;
  }

  bool search(string word) {
    auto cur = head;
    for (auto c : word) {
      if (cur->children[c] == nullptr) return false;
      cur = cur->children[c];
    }
    return cur->is_leaf;
  }

  bool startsWith(string prefix) {
    auto cur = head;
    for (auto c : prefix) {
      if (cur->children[c] == nullptr) return false;
      cur = cur->children[c];
    }
    return true;
  }
};
