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

void print(vector<int>& vec){
  for(int n : vec){
    cout << n << " " ;
  }
  cout << endl;
}

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    vector<int> left_less(size(heights));
    stack<int> left_stack;
    for (int i = 0; i < size(heights); i++) {
      while (
        not empty(left_stack) and heights[i] <= heights[left_stack.top()]) {
        left_stack.pop();
      }
      if (empty(left_stack)) {
        left_less[i] = -1;
      } else {
        left_less[i] = left_stack.top();
      }
      left_stack.push(i);
    }
    vector<int> right_less(size(heights));
    stack<int> right_stack;
    for (int i = size(heights) - 1; i >= 0; i--) {
      while (
        not empty(right_stack) and heights[i] <= heights[right_stack.top()]) {
        right_stack.pop();
      }
      if (empty(right_stack)) {
        right_less[i] = size(heights);
      } else {
        right_less[i] = right_stack.top();
      }
      right_stack.push(i);
    }
    int max_area = 0;
    for(int i = 0; i < size(heights); i++){
      int cur_area = (right_less[i] - left_less[i] - 1) * heights[i];
      max_area = max(max_area, cur_area);
    }
    return max_area;
  }
};

int main(){
  vector<int> heights{2, 1, 5, 6, 2, 3};
  Solution sol;
  cout << sol.largestRectangleArea(heights) << endl;
}
