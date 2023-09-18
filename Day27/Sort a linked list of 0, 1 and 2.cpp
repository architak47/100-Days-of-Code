#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};  

Node* sortList(Node *head){
    Node* temp = head;
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    while(temp){
        if(temp -> data == 0) zeros++;
        else if(temp -> data == 1) ones++;
        else twos++;
        temp = temp -> next;
    }
    temp = head;
    while(zeros--){
        temp -> data = 0;
        temp = temp -> next;
    }
    while(ones--){
        temp -> data = 1;
        temp = temp -> next;
    }
    while(twos--){
        temp -> data = 2;
        temp = temp -> next;
    }
    return head;
}

int main()
{
    cout<<"Code in the backend of compiler\n";

    return 0;
}
