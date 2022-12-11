#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

class Allocator {
  std::unordered_map<ll, std::vector<std::pair<ll, ll>>> alloc;
  std::vector<std::pair<ll, ll>> avail;

 public:
  Allocator(int n) : avail({std::pair<ll, ll>{0, n - 1}}) {}

  int allocate(int size, int mID) {
    for (auto itr = avail.begin(); itr != avail.end(); ++itr) {
      auto &[a, b] = *itr;
      if (b - a + 1 >= size) {
        auto const ans = a;
        alloc[mID].push_back({a, a + size - 1});
        a = a + size;
        if (a > b) {
          avail.erase(itr);
        }
        return ans;
      }
    }
    return -1;
  }

  int free(int mID) {
    ll sum = 0;
    for (auto [a, b] : alloc[mID]) {
      sum += (b - a + 1);
      avail.push_back({a, b});
    }
    alloc.erase(mID);
    std::sort(std::begin(avail), std::end(avail));
    std::vector<std::pair<ll, ll>> tmp;
    for (auto [a, b] : avail) {
      if (tmp.empty())
        tmp.push_back({a, b});
      else if (tmp.back().second != a - 1)
        tmp.push_back({a, b});
      else {
        tmp.back().second = b;
      }
    }
    avail = std::move(tmp);
    return sum;
  }
};
