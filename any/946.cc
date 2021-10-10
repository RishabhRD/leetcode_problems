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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> st;
      int i = 0;
      for(auto n : pushed){
        st.push(n);
        while(size(st) and st.top() == popped[i]){
          st.pop();
          i++;
        }
      }
      return size(st) == 0;
    }
};
