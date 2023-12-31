#include <bits/stdC++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head -> next or !head -> next -> next)return head;
        ListNode* even = head;
        ListNode* odd = head-> next;
        ListNode* temp = head -> next;

        while(even -> next and odd -> next){
            even -> next = odd -> next;
            odd -> next = even -> next -> next;
            even = even -> next;
            odd = odd -> next;
        }
        even -> next = temp;
        return head;
    }
};

int main() {
   cout << "Code in the backend of Compiler";
   return 0;
}