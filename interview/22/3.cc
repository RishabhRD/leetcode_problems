#include <set>
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

class TimeMap {
  unordered_map<string, set<int, greater<int>>> stamp_mp;
  unordered_map<int, unordered_map<string, string>> value_mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
      stamp_mp[key].insert(timestamp);
      value_mp[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
      auto new_timestamp = *stamp_mp[key].lower_bound(timestamp);
      if(new_timestamp > timestamp) return "";
      return value_mp[new_timestamp][key];
    }
};

int main(){
  set<int, greater<int>> st{1, 3,  4};
  auto x = *st.lower_bound(2);
  cout << x << endl;
}
