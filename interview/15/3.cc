class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
      if(head == nullptr) return head;
      auto cur_itr = head;
      while(cur_itr){
        if(not cur_itr->child){
          cur_itr = cur_itr->next;
        }else{
          auto child_tail = cur_itr->child;
          while(child_tail->next){
            child_tail = child_tail->next;
          }
          child_tail->next = cur_itr->next;
          if(cur_itr->next){
            cur_itr->next->prev = child_tail;
          }
          cur_itr->next = cur_itr->child;
          cur_itr->child->prev = cur_itr;
          cur_itr->child = nullptr;
          cur_itr = cur_itr->next;
        }
      }
      return head;
    }
};
