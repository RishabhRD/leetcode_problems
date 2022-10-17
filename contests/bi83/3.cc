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

class NumberContainers {
  std::unordered_map<int, std::set<int>> num_to_idx;
  std::unordered_map<int, int> idx_to_num;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    auto old_idx_itr = idx_to_num.find(index);
    if (old_idx_itr != idx_to_num.end()) {
      num_to_idx[old_idx_itr->second].erase(index);
      if (num_to_idx[old_idx_itr->second].empty())
        num_to_idx.erase(old_idx_itr->second);
    }
    idx_to_num[index] = number;
    num_to_idx[number].insert(index);
  }

  int find(int number) {
    if (num_to_idx.find(number) == num_to_idx.end()) {
      return -1;
    }
    return *(num_to_idx.find(number)->second.begin());
  }
};
