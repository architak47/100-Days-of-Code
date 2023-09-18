#include <bits/stdc++.h>
using namespace std;

class Node {
public:
     int data;
     Node *prev;
     Node *next;
     Node() {
         this->data = 0;
         this->prev = NULL;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->prev = NULL;
         this->next = NULL;
     }
     Node (int data, Node *next, Node *prev) {
         this->data = data;
         this->prev = prev;
         this->next = next;
     }
};

Node * deleteAllOccurrences(Node* head, int k) {
    if(!head) return NULL;
    Node* temp = head;

    while(temp){
        if(temp -> data == k){
            if(temp == head){
                head = head -> next;
            } 
            else{
                temp -> prev -> next = temp -> next;
            }
        }
        temp = temp -> next;
    }
    return head;
}


int main()
{
    cout<<"Code in the backend of compiler\n";

    return 0;
}
