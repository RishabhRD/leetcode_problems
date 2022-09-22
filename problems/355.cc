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

class Twitter {
  std::unordered_map<int, std::unordered_set<int>> user_graph;
  std::unordered_map<int, std::vector<std::pair<int, int>>> tweets_graph;
  int time = 0;

 public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    ++time;
    auto& vec = tweets_graph[userId];
    vec.push_back({time, tweetId});
    if (vec.size() > 10) vec.erase(std::begin(vec));
  }

  std::vector<int> getNewsFeed(int userId) {
    std::vector<std::pair<int, int>> res;
    auto const& following = user_graph[userId];
    for (auto const following_user : following) {
      for (auto tweet : tweets_graph[following_user]) {
        res.push_back(tweet);
      }
    }
    for (auto tweet : tweets_graph[userId]) {
      res.push_back(tweet);
    }
    std::priority_queue<std::pair<int, int>> pq{std::begin(res), std::end(res)};
    std::vector<int> ans;
    for (int i = 0; i < 10; ++i) {
      if (pq.empty()) break;
      auto top = pq.top();
      pq.pop();
      ans.push_back(top.second);
    }
    return ans;
  }

  void follow(int followerId, int followeeId) {
    user_graph[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    user_graph[followerId].erase(followeeId);
  }
};
