#include <queue>
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

class MedianFinder {
  priority_queue<double> less_heap;
  priority_queue<double, vector<double>, greater<double>> greater_heap;
  bool even;

public:
  MedianFinder() : even(true) {}

  void addNum(int num) {
    if(even){
      greater_heap.push(num);
      auto top = greater_heap.top();
      greater_heap.pop();
      less_heap.push(top);
    }else{
      less_heap.push(num);
      auto top = less_heap.top();
      less_heap.pop();
      greater_heap.push(top);
    }
    even = !even;
  }

  double findMedian() {
    if(even)
      return (less_heap.top() + greater_heap.top()) / 2;
    else
      return less_heap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
