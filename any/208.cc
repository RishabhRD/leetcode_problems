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
    vector<trie_node *> children{ 128, nullptr };
    bool is_leaf;
    trie_node() : is_leaf(false) {}
  } * root;

public:
  Trie() : root(new trie_node) {}

  void insert(string word) {
    auto cur_node = root;
    for (auto c : word) {
      if (!cur_node->children[c]) { cur_node->children[c] = new trie_node{}; }
      cur_node = cur_node->children[c];
    }
    cur_node->is_leaf = true;
  }

  bool search(string word) {
    auto cur_node = root;
    for (auto c : word) {
      if (cur_node->children[c]) {
        cur_node = cur_node->children[c];
      } else {
        return false;
      }
    }
    return cur_node->is_leaf == true;
  }

  bool startsWith(string word) {
    auto cur_node = root;
    for (auto c : word) {
      if (cur_node->children[c]) {
        cur_node = cur_node->children[c];
      } else {
        return false;
      }
    }
    return true;
  }
};
