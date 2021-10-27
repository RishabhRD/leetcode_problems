#include <unordered_set>
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

bool contains(unordered_map<int, int> &st, int num) {
  return st.find(num) != st.end();
}

int find(int x, vector<int> &parent) {
  if (parent[x] == -1) return x;
  return parent[x] = find(parent[x], parent);
}

void combine(int x, int y, vector<int> &parent, vector<int> &size) {
  int root_x = find(x, parent);
  int root_y = find(y, parent);
  if (root_x == root_y) return;
  if (size[root_y] > size[root_x]) {
    parent[root_x] = root_y;
    size[root_y] += size[root_x];
  } else {
    parent[root_y] = root_x;
    size[root_x] += size[root_y];
  }
}

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if(empty(nums)) return 0;
    unordered_map<int, int> mp;
    vector<int> parent(size(nums), -1);
    vector<int> sz(size(nums), 1);
    for (int i = 0; i < size(nums); i++) {
      mp[nums[i]] = i;
    }
    for(int i =  0; i < size(nums); i++){
      const int n = nums[i];
      if(contains(mp, n + 1)){
        combine(mp[n], mp[n + 1], parent, sz);
      }
    }
    return *max_element(cbegin(sz), cend(sz));
  }
};
