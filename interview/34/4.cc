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


void print(vector<int>& height){
  for(auto n : height){
    cout << n << " ";
  }
  cout << endl;
}

class Solution {
public:
  int trap(vector<int> &height) {
    const int n = size(height);
    vector<int> left_st;
    vector<int> left_max_vec(n);
    for(int i = 0; i < size(height); i++){
      while(not empty(left_st) and height[left_st.back()] <= height[i]){
        left_st.pop_back();
      }
      if(empty(left_st)){
        left_max_vec[i] = 0;
      }else{
        left_max_vec[i] = height[left_st.front()];
      }
      left_st.push_back(i);
    }

    vector<int> right_st;
    vector<int> right_max_vec(n);
    for(int i = n - 1; i >= 0; i--){
      while(not empty(right_st) and height[right_st.back()] <= height[i]){
        right_st.pop_back();
      }
      if(empty(right_st)){
        right_max_vec[i] = 0;
      }else{
        right_max_vec[i] = height[right_st.front()];
      }
      right_st.push_back(i);
    }


    int sum = 0;
    for(int i = 0; i < n; i++){
      int level = min(left_max_vec[i], right_max_vec[i]);
      int water_acc = level - height[i];
      if(water_acc < 0) water_acc = 0;
      sum += water_acc;
    }
    return sum;
  }
};

/* int main(){ */
/*   vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1}; */
/*   Solution sol; */
/*   sol.trap(height); */
/* } */
