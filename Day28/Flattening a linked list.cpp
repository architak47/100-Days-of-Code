#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
 
 
Node* merge(Node* a, Node* b){
	Node* temp = new Node(0);
	Node* res = temp;

	while(a and b){
		if(a -> data < b -> data){
			temp -> child = a;
			temp = a;
			a = a -> child;
		}
		else{
			temp -> child = b;
			temp = b;
			b = b -> child;
		}
	}
	if(a) temp -> child = a;
	else temp -> child = b;
	return res -> child;
}

Node* flattenLinkedList(Node* head) 
{
	if(!head || !head -> next) return head;
	
	Node* right = flattenLinkedList(head -> next);
	head -> next = 0;
	Node* ans = merge(head, right);

	return ans;
}


int main()
{
    cout<<"Code in the backend of compiler\n";

    return 0;
}
