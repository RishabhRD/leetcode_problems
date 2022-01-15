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
  vector<int> majorityElement(vector<int> &nums) {
    int cand1 = -1;
    int cand2 = -1;
    int count1 = 0;
    int count2 = 0;
    for (auto x : nums) {
      if (x == cand1)
        count1++;
      else if (x == cand2)
        count2++;
      else if (count1 == 0) {
        cand1 = x;
        count1 = 1;
      } else if (count2 == 0) {
        cand2 = x;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }
    cout << cand1 << " " << cand2 << endl;
    vector<int> res;
    count1 = count(cbegin(nums), cend(nums), cand1);
    count2 = count(cbegin(nums), cend(nums), cand2);
    if (count1 > (size(nums) / 3)) res.push_back(cand1);
    if (count2 > (size(nums) / 3) && cand1 != cand2) res.push_back(cand2);
    return res;
  }
};

int main() {
  vector<int> nums = { 3, 2, 3 };
  Solution sol;
  sol.majorityElement(nums);
}
