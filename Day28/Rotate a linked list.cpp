#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

int len(Node* head){
     int cnt = 0;
     while(head){
          cnt++;
          head = head -> next;
     }
     return cnt;
}
Node *rotate(Node *head, int k) {
     int cnt = len(head);
     k = k % cnt;
     if(!head || !head->next || k == 0) return head;
     Node* slow = head;
     Node* fast = head;
     Node* temp = head;

     while(k--){
          fast = fast -> next;
     }

     while(fast -> next){
          fast = fast -> next;
          slow = slow -> next;
     }
     temp = slow -> next;
     slow -> next = nullptr;
     fast -> next = head;
     return temp;
}

int main()
{
    cout<<"Code in the backend of compiler\n";

    return 0;
}
