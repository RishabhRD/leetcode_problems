#include <list>
#include <random>
#include <chrono>
#include <iostream>
#include <execution>
#include <numeric>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>> const &accounts) {
  return transform_reduce(
    cbegin(accounts),
    cend(accounts),
    0,
    [](auto a, auto b) { return max(a, b); },
    [](auto const &vec) { return reduce(begin(vec), end(vec), 0); });
}
