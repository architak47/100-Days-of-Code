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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int carry = 0;
        
        while(l1 || l2 || carry){
            int num = 0;
            if(l1){
                num += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                num += l2 -> val;
                l2 = l2 -> next;
            }
            if(carry){
                num += carry;
            }
            carry = num / 10;
            num %= 10;
            ListNode* var = new ListNode(num);
            temp -> next = var;
            temp = temp -> next;
        }
        return head -> next;
    }
};

int main()
{
    cout<<"Code in the backend of compiler\n";

    return 0;
}
