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

class Solution {
 public:
  std::vector<std::string> topKFrequent(std::vector<std::string>& words,
                                        int k) {
    std::unordered_map<std::string_view, int> freq_mp;
    for (std::string_view word : words) ++freq_mp[word];
    std::vector<std::string_view> uniq_words;
    for (auto [word, freq] : freq_mp) {
      uniq_words.push_back(word);
    }

    auto cmp = [&freq_mp](std::string_view word1, std::string_view word2) {
      if (freq_mp[word1] == freq_mp[word2])
        return word1 > word2;
      else
        return freq_mp[word1] < freq_mp[word2];
    };

    std::priority_queue<std::string_view, std::vector<std::string_view>,
                        decltype(cmp)>
        pq(std::begin(uniq_words), std::end(uniq_words), cmp);

    std::vector<std::string> res;
    for (int i = 0; i < k and not std::empty(pq); ++i) {
      auto const top = pq.top();
      pq.pop();
      res.push_back(std::string{top});
    }
    return res;
  }
};
