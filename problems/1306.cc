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

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    int const n = size(arr);
    queue<int> q;
    q.push(start);
    vector visited(n, false);
    while (not empty(q)) {
      auto top = q.front();
      q.pop();
      visited[top] = true;
      if (arr[top] == 0) return true;
      if (top + arr[top] < n and not visited[top + arr[top]])
        q.push(top + arr[top]);
      if (top - arr[top] >= 0 and not visited[top - arr[top]])
        q.push(top - arr[top]);
    }
    return false;
  }
};
