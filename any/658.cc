#include <cmath>
#include <queue>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x) {
  int n = size(arr);
  int high = lower_bound(cbegin(arr), cend(arr), x) - begin(arr);
  int low = high - 1;
  while(k--){
    if(high >= n || low >= 0 && abs(x - arr[low]) <= abs(x - arr[high])) low--;
    else high++;
  }
  return vector(cbegin(arr) + low + 1, cbegin(arr) + high);
}
