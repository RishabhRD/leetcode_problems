#include <bitset>
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
  uint32_t reverseBits(uint32_t n) {
    // auto str = bitset<32>{ n }.to_string();
    // reverse(begin(str), end(str));
    // return bitset<32>(str).to_ullong();
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
      result <<= 1;
      result |= (n & 1);
      n >>= 1;
    }
    return result;
  }
};

void print(uint32_t num) { cout << bitset<32>{ num }.to_string() << endl; }

int main() {
  uint32_t num{ 6 };
  num >>= 1;
  print(num);
  num >>= 1;
  print(num);
  num >>= 1;
  print(num);
}
