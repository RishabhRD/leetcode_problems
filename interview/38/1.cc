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
  vector<int> sortArrayByParityII(vector<int> &nums) {
    vector<int> even_arr;
    copy_if(begin(nums), end(nums), back_inserter(even_arr), [](int x) {
      return x % 2 == 0;
    });
    vector<int> odd_arr;
    copy_if(begin(nums), end(nums), back_inserter(odd_arr), [](int x) {
      return x % 2 == 1;
    });
    int idx = 0;
    vector<int> final_arr;
    for (int i = 0; i < size(even_arr); i++) {
      final_arr.push_back(even_arr[i]);
      final_arr.push_back(odd_arr[i]);
    }
    return final_arr;
  }
};
