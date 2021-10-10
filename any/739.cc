#include <stack>
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<pair<int, int>> st;
      int n = size(temperatures);
      vector<int> ans(size(temperatures));
      for(int i = n - 1; i >= 0; i--){
        while(not empty(st) and st.top().first <= temperatures[i]){
          st.pop();
        }
        if(empty(st)) ans[i] = 0;
        else{
          ans[i] = st.top().second - i;
        }
        st.emplace(temperatures[i], i);
      }
      return ans;
    }
};
