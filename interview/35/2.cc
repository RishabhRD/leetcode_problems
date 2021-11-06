#include <unordered_set>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

string to_lower(const string &str) {
  string s;
  for (auto c : str) { s += tolower(c); }
  return s;
}

string devowel(const string &str) {
  string s;
  for (auto c : str) {
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
      s += '#';
    else
      s += c;
  }
  return s;
}

class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist,
    vector<string> &queries) {
    unordered_map<string, string> lower_mp;
    unordered_map<string, string> vowel_mp;
    unordered_set<string> words;
    vector<string> ans;
    for (const string &str : wordlist) {
      words.insert(str);
      auto lower = to_lower(str);
      auto dev = devowel(lower);
      lower_mp.insert({ lower, str });
      vowel_mp.insert({ dev, str });
    }
    for (const auto &q : queries) {
      auto lower = to_lower(q);
      auto dev = devowel(lower);
      if (words.find(q) != words.end()) {
        cout << "word: " << q << endl;
        ans.push_back(q);
      } else if (lower_mp.find(lower) != lower_mp.end()) {
        cout << "lower: " << lower_mp[lower] << endl;
        ans.push_back(lower_mp[lower]);
      } else if (vowel_mp.find(dev) != vowel_mp.end()) {
        cout << "dev: " << vowel_mp[dev] << endl;
        ans.push_back(vowel_mp[dev]);
      } else {
        cout << "empty: " << "" << endl;
        ans.push_back("");
      }
    }
    return ans;
  }
};

void print(const vector<string>& vec){
  for(string_view s : vec) cout << s << " ";
  cout << endl;
}

int main() {
  vector<string> wordlist{ "KiTe", "kite", "hare", "Hare" };
  vector<string> query {
    "kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet",
      "keto"
  };

  Solution sol;
  print(sol.spellchecker(wordlist, query));
}
