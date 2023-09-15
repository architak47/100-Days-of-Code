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
private:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(temp){
            next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) return true;
        ListNode* slow = head, *fast = head;
        
        while(fast -> next and fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* rev = reverse(slow -> next);
        ListNode* temp = head;

        while(rev and temp){
            if(rev -> val != temp -> val) return false;
            rev = rev -> next;
            temp = temp -> next;
        }
    return true;
    }
};

int main()
{
    // code in the backend of compiler

    return 0;
}
