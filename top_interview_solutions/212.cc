#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

struct trie_node {
  std::vector<trie_node*> children{26, nullptr};
  std::optional<std::string> word;
};

struct trie {
  trie_node* head = new trie_node;

  void insert(std::string str) {
    auto cur = head;
    for (auto c : str) {
      if (cur->children[c - 'a'] == nullptr) {
        cur->children[c - 'a'] = new trie_node;
      }
      cur = cur->children[c - 'a'];
    }
    cur->word = std::move(str);
  }
};

trie build_trie(std::vector<std::string> const& words) {
  trie trie;
  for (auto word : words) {
    trie.insert(std::move(word));
  }
  return trie;
}

void dfs(ll i, ll j, std::vector<std::vector<char>>& board, trie_node* head,
         std::vector<std::string>& res) {
  if (board[i][j] == '#') return;

  if (head->children[board[i][j] - 'a'] == nullptr) return;
  head = head->children[board[i][j] - 'a'];
  if (head->word) {
    res.push_back(head->word.value());
    head->word = std::nullopt;
  }
  auto const cur = board[i][j];
  board[i][j] = '#';
  if (i > 0) dfs(i - 1, j, board, head, res);
  if (i < board.size() - 1) dfs(i + 1, j, board, head, res);
  if (j > 0) dfs(i, j - 1, board, head, res);
  if (j < board[0].size() - 1) dfs(i, j + 1, board, head, res);
  board[i][j] = cur;
}

class Solution {
 public:
  std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                     std::vector<std::string>& words) {
    auto trie = build_trie(words);
    std::vector<std::string> res;
    for (ll i = 0; i < board.size(); ++i) {
      for (ll j = 0; j < board[0].size(); ++j) {
        dfs(i, j, board, trie.head, res);
      }
    }
    return res;
  }
};
