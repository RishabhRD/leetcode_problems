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

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    vector<pair<double, int>> workers;
    for(int i = 0; i < size(quality); i++){
      workers.emplace_back((double)(wage[i]) / quality[i], quality[i]);
    }
    sort(begin(workers), end(workers));
    priority_queue<int> pq;
    int q_sum = 0;
    double res = numeric_limits<double>::max();
    for(auto [ratio, quality] : workers){
      q_sum += quality;
      pq.push(quality);
      if(size(pq) > k){
        q_sum -= pq.top();
        pq.pop();
      }
      if(size(pq) == k){
        res = min(res, q_sum * ratio);
      }
    }
    return res;
  }
};
