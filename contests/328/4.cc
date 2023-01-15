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

struct node_desc {
  ll dist1;
  ll n1;
  ll dist2;
  ll n2;
};

node_desc op(node_desc d, ll dist, ll node) {
  if (dist >= d.dist1) {
    d.dist2 = d.dist1;
    d.n2 = d.n1;
    d.n1 = node;
    d.dist1 = dist;
  } else if (dist >= d.dist2) {
    d.n2 = node;
    d.dist2 = dist;
  }
  return d;
}

ll dfs1(ll i, ll parent, std::vector<std::vector<ll>> const& graph,
        std::vector<int> const& price, std::vector<node_desc>& dp) {
  for (auto n : graph[i]) {
    if (n != parent) {
      dp[i] = op(dp[i], price[i] + dfs1(n, i, graph, price, dp), n);
    }
  }
  return dp[i].dist1;
}

void dfs2(ll i, ll parent, std::vector<std::vector<ll>> const& graph,
          std::vector<int> const& price, std::vector<node_desc>& dist,
          std::vector<ll>& dp) {
  if (dist[parent].n1 == i) {
    dist[i] = op(dist[i], price[i] + dist[parent].dist2, parent);
  } else {
    dist[i] = op(dist[i], price[i] + dist[parent].dist1, parent);
  }
  dp[i] = dist[i].dist1 - price[i];
  for (auto n : graph[i]) {
    if (n != parent) {
      dfs2(n, i, graph, price, dist, dp);
    }
  }
}

class Solution {
 public:
  long long maxOutput(int n, std::vector<std::vector<int>>& edges,
                      std::vector<int>& price) {
    std::vector<std::vector<ll>> tree(n);
    for (auto const& edge : edges) {
      auto const u = edge[0];
      auto const v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    std::vector<node_desc> dist(n);
    for (ll i = 0; i < n; ++i) {
      dist[i].n1 = i;
      dist[i].n2 = i;
      dist[i].dist1 = price[i];
      dist[i].dist2 = price[i];
    }
    dfs1(0, 0, tree, price, dist);
    // for (ll i = 0; i < n; ++i) {
    //   std::cout << dist[i].n1 << ' ' << dist[i].dist1 << ' ' << dist[i].n2
    //             << ' ' << dist[i].dist2 << std::endl;
    // }
    std::vector<ll> res(n);
    res[0] = dist[0].dist1 - price[0];
    for (auto n : tree[0]) {
      dfs2(n, 0, tree, price, dist, res);
    }
    return *std::max_element(std::begin(res), std::end(res));
  }
};
