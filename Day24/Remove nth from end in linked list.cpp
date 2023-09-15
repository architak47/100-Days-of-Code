#include <bits/stdc++.h>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* temp = new ListNode();
        temp -> next = head;
        ListNode* slow = temp;
        ListNode* fast = temp;

        while(n > 0){
            fast = fast -> next;
            n--;
        }

        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }

        slow -> next = slow -> next -> next;

        return temp -> next;

    }
};

int main()
{
    // code in the backend of compiler

    return 0;
}
