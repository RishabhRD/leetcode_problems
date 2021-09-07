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

int width(const vector<int> &book) { return book[0]; }

int height(const vector<int> &book) { return book[1]; }

int max_height(const vector<vector<int>> &books,
  const int i,
  int shelf_width,
  vector<int> &dp) {
  if(i == size(books)) return 0;
  if(dp[i] >= 0) return dp[i];
  int cur_width = 0;
  int cur_height = 0;
  int ans = INT32_MAX;
  for (int cur = i; cur < size(books); cur++) {
    cur_width += width(books[cur]);
    if (cur_width > shelf_width) { break; }
    cur_height = max(cur_height, height(books[cur]));
    ans = min(ans, cur_height + max_height(books, cur + 1, shelf_width, dp));
  }
  dp[i] = ans;
  return ans;
}

class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    const int n = size(books);
    vector<int> dp(n + 1, -1);
    return max_height(books, 0, shelfWidth, dp);
  }
};

int main(){
  Solution sol;
  vector<vector<int>> books{
    {1, 3}, {2, 4}, {3, 2}
  };
  int shelfWidth = 6;
  cout << sol.minHeightShelves(books, shelfWidth) << endl;
}
