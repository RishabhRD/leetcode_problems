#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
  long long maximumSubsequenceCount(string const text, string const pattern) {
    auto const [cnt0, num_subseq] =
      accumulate(begin(text), end(text), pair{ 0ll, 0ll }, [&](auto p, auto c) {
        if (c == pattern[1]) p.second += p.first;
        if (c == pattern[0]) ++p.first;
        return p;
      });
    auto const cnt1 = count(begin(text), end(text), pattern[1]);
    return max(cnt0 + num_subseq, cnt1 + num_subseq);
  }
};
