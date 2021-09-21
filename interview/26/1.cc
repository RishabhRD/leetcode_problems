#include <unordered_set>
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
  int uniqueMorseRepresentations(vector<string> &words) {
    constexpr static array arr{ ".-",
      "-...",
      "-.-.",
      "-..",
      ".",
      "..-.",
      "--.",
      "....",
      "..",
      ".---",
      "-.-",
      ".-..",
      "--",
      "-.",
      "---",
      ".--.",
      "--.-",
      ".-.",
      "...",
      "-",
      "..-",
      "...-",
      ".--",
      "-..-",
      "-.--",
      "--.." };
    unordered_set<string> st;
    for (string_view s : words) {
      string new_str;
      for(auto c : s){
        new_str += arr[c - 'a'];
      }
      st.insert(new_str);
    }
    return size(st);
  }
};
