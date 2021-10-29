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
  int findShortestSubArray(vector<int> &nums) {
    unordered_map<int, int> cnt, fst;
    const int inf = size(nums) + 1;
    int min_len = 1;
    int max_count = 0;
    for (int i = 0; i < size(nums); i++) {
      const int num = nums[i];
      cnt[num]++;
      if(fst.find(num) == fst.end()){
        fst[num] = i;
      }
      if(cnt[num] > max_count){
        max_count = cnt[num];
        min_len = i - fst[num] + 1;
      }else if(cnt[num] == max_count){
        min_len = min(min_len, i - fst[num] + 1);
      }
    }
    return min_len;
  }
};

int main() {
  Solution sol;
  vector<int> nums{ 1, 2, 2, 3, 1 };
  cout << sol.findShortestSubArray(nums) << endl;
}
