#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
int length(ListNode* head){
  int cnt = 0;
  while(head){
    head = head -> next;
    cnt++;
  }
  return cnt;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head || !head -> next){
        return head;
      }
      int len = length(head);
      ListNode* ans = new ListNode();
      ans -> next = head;
      ListNode* prev = ans;

      ListNode* temp;
      ListNode* next;

      while(len >= k){
        temp = prev -> next;
        next = temp -> next;
        for(int i = 1; i < k; i++){
          temp -> next = next -> next;
          next -> next = prev -> next;
          prev -> next = next;
          next = temp -> next;
        }
        prev = temp;
        len -= k;
      }
      return ans -> next;
    }
};

int main()
{
    cout<<"Code in the backend of compiler\n";

    return 0;
}
