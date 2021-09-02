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

struct trie_node {
  bool is_leaf;
  array<trie_node *, 27> children{};
  trie_node(bool is_leaf = false) : is_leaf(is_leaf) {}
};

bool contains(trie_node* cur_node, char c) {
  size_t ind = c - 'a';
  return cur_node->children[ind] != nullptr;
}

auto get(trie_node* cur_node, char c) -> trie_node*&{
  size_t ind = c - 'a';
  return cur_node->children[ind];
}

template <typename Itr>
bool search(Itr begin, Itr end, trie_node* cur_node){
  if(begin == end){
    return cur_node->is_leaf;
  }
  if(*begin == '.'){
    for(int i = 0; i < 26; i++){
      if(contains(cur_node, i + 'a')){
        auto res = search(begin + 1, end, get(cur_node, i + 'a'));
        if(res == true) return true;
      }
    }
    return false;
  }else{
    if(contains(cur_node, *begin)){
      return search(begin + 1, end, get(cur_node, *begin));
    }else{
      return false;
    }
  }
}

class WordDictionary {
  trie_node *root;


public:
  WordDictionary() : root(new trie_node) {}

  void addWord(string word) {
    auto cur_node = root;
    for (auto c : word) {
      if(!contains(cur_node, c)){
        get(cur_node, c) = new trie_node;
      }
      cur_node = get(cur_node, c);
    }
    cur_node->is_leaf = true;
  }

  bool search(string word) {
    return ::search(cbegin(word), cend(word), root);
  }
};
