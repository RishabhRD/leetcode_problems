#include <list>
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

vector<int> solve(const vector<int> &arr, int m, int x) {
  list<int> lst{ arr.begin(), arr.end() };
  int size = lst.size();
  vector<decltype(lst)::iterator> vec;
  for (auto itr = lst.begin(); itr != prev(lst.end()); itr++) {
    if (abs(*itr - *(next(itr))) > x) { vec.push_back(itr); }
  }
  if (size + vec.size() > m) { return { -1 }; }

  for (int i = 0; i < vec.size(); i++) {
    auto itr = vec[i];
    int sum = *itr + *next(itr);
    auto first_val = *itr;
    auto second_val = *next(itr);
    auto new_itr = lst.insert(next(itr), sum / 2);
    auto first_diff = abs((sum / 2) - first_val);
    if (first_diff > x) { vec.push_back(itr); }
    auto second_diff = abs((sum / 2) - second_val);
    if (second_diff > x) { vec.push_back(new_itr); }
  }
  return vector<int>{ lst.begin(), lst.end() };
}

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) { cin >> arr[i]; }
  vector<int> res = solve(arr, m, x);
  if(res.size() > m ) cout << -1 << endl;
  else if (res.size() == 1 and res[0] == -1) {
    cout << -1 << endl;
  } else {
    cout << res.size() << endl;
    for (auto x : res) { cout << x << " "; }
    cout << endl;
  }
}
