#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
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

class union_find {
  int n;
  vector<int> parent;

public:
  union_find(int n) : n(n), parent(n) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  void combine(int i, int j) { parent[find(i)] = parent[find(j)]; }

  int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
  }
};

template<typename Cont, typename Val> bool contains(Cont &cont, Val &val) {
  return cont.find(val) != cont.end();
}

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    const int n = size(accounts);
    union_find uf(size(accounts));
    unordered_map<string, int> st_to_int;
    for (int i = 0; i < size(accounts); i++) {
      auto &acc = accounts[i];
      for (int j = 1; j < size(acc); j++) {
        auto& str = acc[j];
        if (contains(st_to_int, str)) {
          uf.combine(i, st_to_int[str]);
        } else {
          st_to_int[str] = i;
        }
      }
    }
    vector<set<string>> ds(size(accounts));
    for(int i = 0; i < n; i++){
      int parent = uf.find(i);
      auto& st = ds[parent];
      st.insert(next(begin(accounts[i])), end(accounts[i]));
    }

    vector<vector<string>> vec;
    for(int i = 0; i < n; i++){
      auto& st = ds[i];
      if(empty(st)) continue;
      vector<string> cur_vec;
      cur_vec.push_back(accounts[i][0]);
      cur_vec.insert(end(cur_vec), begin(st), end(st));
      vec.push_back(std::move(cur_vec));
    }
    return vec;
  }
};
