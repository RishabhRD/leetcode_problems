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

bool is_symbol(string_view str) {
  return size(str) == 1
         and (str[0] == '+' or str[0] == '-' or str[0] == '*' or str[0] == '/');
}

int get_num(string_view str) {
  if (str[0] == '-') {
    int num = 0;
    for (int i = 1; i < size(str); i++) { num = num * 10 + (str[i] - '0'); }
    return -num;
  } else {
    int num = 0;
    for (char c : str) { num = num * 10 + (c - '0'); }
    return num;
  }
}

int get_result(int snd, int fst, char sym) {
  if (sym == '*')
    return fst * snd;
  else if (sym == '+')
    return fst + snd;
  else if (sym == '-')
    return fst - snd;
  else
    return fst / snd;
}

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    vector<int> st;
    for (string_view str : tokens) {
      if (is_symbol(str)) {
        auto top1 = st.back();
        st.pop_back();
        auto top2 = st.back();
        st.pop_back();
        st.push_back(get_result(top1, top2, str[0]));
      } else {
        st.push_back(get_num(str));
      }
    }
    return st.back();
  }
};
