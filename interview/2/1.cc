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

bool isIsomorphic(string s, string t) {
  const int n = size(s);
  if(n != size(t)) return false;
  unordered_set<char> st;
  unordered_map<char, char> mp;
  for(int i = 0; i < n; i++){
    if(mp.find(s[i]) != mp.end()){
      auto old_val = mp[s[i]];
      if(old_val != t[i]) return false;
    }else{
      if(st.find(t[i]) != st.end()){
        return false;
      }
      mp[s[i]] = t[i];
      st.insert(t[i]);
    }
  }
  return true;
}
