#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int min_white(string_view floor, int idx, int num_carpets, int len, vector<int> const &num_white, vector<vector<int>> &dp) {
    if (idx >= size(floor))
        return 0;
    if (num_carpets == 0)
        return num_white[idx];
    if (dp[idx][num_carpets] != -1) {
        return dp[idx][num_carpets];
    }
    if (floor[idx] == '1') {
        return dp[idx][num_carpets] = min(1 + min_white(floor, idx + 1, num_carpets, len, num_white, dp),
                                          min_white(floor, idx + len, num_carpets - 1, len, num_white, dp));
    } else {
        return dp[idx][num_carpets] = min_white(floor, idx + 1, num_carpets, len, num_white, dp);
    }
}

class Solution {
    public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        vector<int> num_white;
        int num_white_cur = 0;
        vector dp(size(floor) + 1, vector(numCarpets + 1, -1));
        for_each(rbegin(floor), rend(floor), [&](auto c) {
            if (c == '1') {
                ++num_white_cur;
            }
            num_white.push_back(num_white_cur);
        });
        reverse(begin(num_white), end(num_white));
        return min_white(floor, 0, numCarpets, carpetLen, num_white, dp);
    }
};

int main() {
    Solution sol;
    cout << sol.minimumWhiteTiles("10110101", 2, 2) << endl;
}
