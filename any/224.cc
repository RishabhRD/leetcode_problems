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
bool is_digit(char c) { return c >= '0' and c <= '9'; }

class Solution {
public:
  int calculate(string s) {
    stack<int> result_stack;
    int result = 0;
    int number = 0;
    int sign = 1;
    for (auto c : s) {
      if (is_digit(c)) {
        number = number * 10 + (c - '0');
      } else if (c == '+') {
        result += number * sign;
        sign = 1;
        number = 0;
      } else if (c == '-') {
        result += number * sign;
        sign = -1;
        number = 0;
      } else if (c == '(') {
        result_stack.push(result);
        result_stack.push(sign);
        sign = 1;
        number = 0;
        result = 0;
      } else if (c == ')') {
        result += sign * number;
        number = 0;
        sign = 1;
        result *= result_stack.top();
        result_stack.pop();
        result += result_stack.top();
        result_stack.pop();
      }
    }
    result += sign * number;
    return result;
  }
};
