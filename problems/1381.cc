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

class CustomStack {
  int maxSize;
  vector<int> vec;
  vector<int> inc;
public:
    CustomStack(int maxSize) : maxSize(maxSize), inc(maxSize){}
    
    void push(int x) {
      if(size(vec) != maxSize){
        vec.push_back(x);
      }
    }
    
    int pop() {
      int i = size(vec) - 1;
      if(i < 0) return -1;
      if(i > 0)
        inc[i - 1] += inc[i];
      int top = vec.back() + inc[i];
      inc[i] = 0;
      vec.pop_back();
      return top;
    }
    
    void increment(int k, int val) {
      int i = min(k, (int)size(vec)) - 1;
      if(i >= 0) inc[i] += val;
    }
};
