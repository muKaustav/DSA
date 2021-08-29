#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int val){
		data = val;
		next = NULL;
	}
};

void insertAtTail(node* &head, int val){
	node* n = new node(val);

	if(head == NULL){
		head = n;
		return;
	}

	node* temp = head;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = n;
}

int length(node* root){
	if(root == NULL)
		return 0;
	else
		return 1 + length(root->next);
}

node* reverse(node* head, node* tail){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;

	while(currptr != tail){
		nextptr = currptr->next;
		currptr->next = prevptr;

		prevptr = currptr;
		currptr = nextptr;
	}

	return prevptr;
}

node* reverseKbatch(node* head, int k){
	node* ptr = head;

	for(int i = 0; i < k; i++){
		if(!ptr)
			return head;
		else
			ptr = ptr->next;
	}

	node* temp = reverse(head, ptr);
	head->next = reverseKbatch(ptr, k);

	return temp;
}

node* reverseK(node* &head, int k){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;

	int c = 0;

	while(currptr != NULL && c < k){
		nextptr = currptr->next;
		currptr->next = prevptr;

		prevptr = currptr;
		currptr = nextptr;

		c++;
	}

	if(nextptr != NULL)
		head->next = reverseK(nextptr, k);

	return prevptr;
}

void display(node* head){
	node* temp = head;

	while(temp != NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

int main(){

	node* head = NULL;
	node* head1 = NULL;

	int k = 3;

	insertAtTail(head, 10);
	insertAtTail(head, 20);
	insertAtTail(head, 30);
	insertAtTail(head, 40);
	insertAtTail(head, 50);
	insertAtTail(head, 60);
	
	// insertAtTail(head1, 1);
	// insertAtTail(head1, 2);
	// insertAtTail(head1, 3);
	// insertAtTail(head1, 4);
	// insertAtTail(head1, 5);

	node* newHead = reverseKbatch(head, 4);
	// node* newHead1 = reverseK(head1, k);

	display(newHead); 
	// display(newHead1); 

	return 0;
}