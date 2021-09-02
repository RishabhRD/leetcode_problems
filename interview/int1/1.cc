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
bool isBadVersion(int);

int firstBadVersion(int n) {
  int low = 0;
  int high = n;
  while(low < high){
    int mid = low + (high - low) / 2;
    if(isBadVersion(mid)){
      high = mid;
    }else{
      low = mid + 1;
    }
  }
  return low;
}
