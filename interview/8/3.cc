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

struct item {
  int val;
  int label;
};

class Solution {
public:
  int largestValsFromLabels(vector<int> &values,
    vector<int> &labels,
    int numWanted,
    int useLimit) {
    vector<item> items;
    const int n = size(values);
    transform(cbegin(values),
      cend(values),
      cbegin(labels),
      back_inserter(items),
      [](int val, int label) -> item {
        return { val, label };
      });
    sort(
      begin(items), end(items), [](auto a, auto b) { return a.val > b.val; });
    int count = 0;
    int ans = 0;
    unordered_map<int, int> lbl_count;
    for(auto& [val, label] : items){
      if(lbl_count[label] == useLimit){
        continue;
      }else if(count == numWanted){
        break;
      }
      lbl_count[label]++;
      ans += val;
      count++;
    }
    return ans;
  }
};
