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

char find(char c, unordered_map<char, char>& mp){
  if(mp[c] == 0) return c;
  return (mp[c] = find(mp[c], mp));
}

bool combine(char a, char b, unordered_map<char, char>& parent, unordered_map<char, int>& size){
  auto root_a = find(a, parent);
  auto root_b = find(b, parent);
  if(root_a == root_b) return false;
  if(size[root_a] > size[root_b]){
    parent[root_b] = root_a;
    size[root_a] += size[root_b];
  }else{
    parent[root_a] = root_b;
    size[root_b] += size[root_a];
  }
  return true;
}

bool is_inequality(string_view str){
  return str[1] == '!';
}

auto get_operands(string_view str){
  return pair{str[0], str[3]};
}

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
      vector<string_view> inequal_strings;
      unordered_map<char, int> size;
      unordered_map<char, char> parent;
      for(const auto& eq : equations){
        if(is_inequality(eq)){
          inequal_strings.emplace_back(eq);
        }else{
          auto [fst, snd] = get_operands(eq);
          if(size[fst] == 0) size[fst] = 1;
          if(size[snd] == 0) size[snd] = 1;
          combine(fst, snd, parent, size);
        }
      }
      for(auto str : inequal_strings){
        auto [fst, snd] = get_operands(str);
        if(find(fst, parent) == find(snd, parent)){
          return false;
        }
      }
      return true;
    }
};
