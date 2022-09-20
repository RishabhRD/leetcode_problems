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

struct trie_node {
  int val{1};
  std::array<trie_node *, 26> children{nullptr};
};

void insert(trie_node *head, std::string_view word) {
  auto cur = head;
  for (auto c : word) {
    if (cur->children[c - 'a'] == nullptr) {
      cur->children[c - 'a'] = new trie_node;
    } else {
      ++cur->children[c - 'a']->val;
    }
    cur = cur->children[c - 'a'];
  }
}

int score(trie_node *head, std::string_view word) {
  auto cur = head;
  int score = 0;
  for (auto c : word) {
    score += cur->children[c - 'a']->val;
    cur = cur->children[c - 'a'];
  }
  return score;
}

class Solution {
 public:
  std::vector<int> sumPrefixScores(std::vector<std::string> &words) {
    trie_node *head = new trie_node;
    for (std::string_view word : words) {
      insert(head, word);
    }
    std::vector<int> ans(std::size(words));
    for (int i = 0; i < std::size(words); ++i) {
      std::string_view word = words[i];
      ans[i] = score(head, word);
    }
    return ans;
  }
};
