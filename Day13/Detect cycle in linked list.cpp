#include <bits/stdc++.h>
using namespace std;

class ListNode{
    int num;
        ListNode* next;
        ListNode(int val) {
            num = val;
            next = NULL;
        }
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(fast and  fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
    return false;
}

int main()
{
    /* 
    
    Writing the whole code for linked insertion and all its features is not yet possible for me but I assure that when I reach to Linked list I'll write whole code with out put for linked list insertion and define a listNode class and publish it here on my challenge currently I am solving Binary search problems and I just solved this problem because it is there in my today's code because it is daily challenge on Leetcode and love to solve it.

    Thank you

    */
}
