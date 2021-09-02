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

bool is_alpha(char c){
  int num = c - 'a';
  return num >= 0 and num < 26;
}

bool is_number(char c){
  int num = c - '0';
  return num >= 0 and num <= 9;
}

template <typename Itr>
int get_num(Itr& begin){
  int num = 0;
  while(is_number(*begin)){
    num = (10 * num + ((*begin) - '0'));
    begin++;
  }
  return num;
}

template <typename Itr>
string get_string(Itr& begin){
  string res = "";
  int count = 1;
  begin++;
  while(true){
    if(*begin == ']'){
      count--;
      if(count == 0){
        begin++;
        break;
      }
    }else if(*begin == '[') count++;
    res += *begin;
    begin++;
  }
  return res;
}


template <typename Itr>
string decode(const Itr begin, const Itr end){
  string res = "";
  auto itr = begin;
  while(itr != end){
    if(is_alpha(*itr)){
      res += *itr;
      itr++;
    }else{
      int repetition = get_num(itr);
      string str = get_string(itr);
      string decoded_str = decode(cbegin(str), cend(str));
      for(int i = 0; i < repetition; i++){
        res += decoded_str;
      }
    }
  }
  return res;
}


class Solution {
public:
    string decodeString(string s) {
      return decode(cbegin(s), cend(s));
    }
};

int main(){
  Solution s;
  cout << s.decodeString("3[a2[c]]") << endl;
}
