#include <unordered_map>
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

class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<size_t> last_pos(128);
    vector<int> res;
    for(size_t i = 0; i < size(s); i++){
      last_pos[s[i]] = i;
    }
    for(size_t i = 0, last_idx = 0, idx = 0; i < size(s); i++){
      idx = max(idx, last_pos[s[i]]);
      if(idx == i)
        res.push_back(i - exchange(last_idx, i + 1) + 1);
    }
    return res;
  }
};
