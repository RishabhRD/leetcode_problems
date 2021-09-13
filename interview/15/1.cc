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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool is_palindrome(const vector<int>& vec){
  int n = size(vec);
  for(int i = 0; i < n / 2; i++){
    if(vec[i] != vec[n - i - 1]) return false;
  }
  return true;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      vector<int> vec;
      while(head){
        vec.push_back(head->val);
        head = head->next;
      }
      return is_palindrome(vec);
    }
};

int main(){
  cout << is_palindrome({1, 2, 2, 1}) << endl;
}
