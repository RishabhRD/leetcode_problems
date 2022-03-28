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
  int evalRPN(vector<string> &tokens) {
    unordered_map<string_view, function<int(int, int)>> const mp{
      { "+", plus{} },
      { "-", minus{} },
      { "*", multiplies{} },
      { "/", divides{} },
    };
    stack<int> st;
    for (auto const &str : tokens) {
      if (mp.find(str) != mp.end()) {
        auto const n2 = st.top();
        st.pop();
        auto const n1 = st.top();
        st.pop();
        st.push(mp.at(str)(n1, n2));
      } else {
        st.push(stoi(str));
      }
    }
    return st.top();
  }
};

int main() {
  vector<string> tokens{
    "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
  };
  Solution sol;
  cout << sol.evalRPN(tokens) << endl;
}
