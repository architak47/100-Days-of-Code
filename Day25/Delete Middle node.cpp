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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast and fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = slow -> next;
        slow = NULL;
        fast = NULL;
        return head;
    }
};

int main() {
   cout << "Code in the backend of Compiler";
   return 0;
}