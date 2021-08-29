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

void insertAtHead(node* &head, int val){
	
	node* n = new node(val);

	if(head == NULL){
		n->next = n;
		head = n;
		return;
	}
	
	node* temp = head;

	while(temp->next != head)
		temp = temp->next;
	
	temp->next = n;
	n->next = head;
	head = n;
}

void insertAtTail(node* &head, int val){
	
	node* n = new node(val);

	if(head == NULL){
		insertAtHead(head, val);
		return;
	}

	node* temp = head;

	while(temp->next != head)
		temp = temp->next;

	temp->next = n;
	n->next = head;
}

void deletion(node* &head, int val){
	if(head == NULL)
		return;

	if(head->next == head){
		delete head;
		return;
	}

	if(head->data == val){
		node* temp = head;

		while(temp->next != head)
			temp = temp->next;

		node* todelete = head;
		
		temp->next = head->next;
		head = head->next;
		
		delete todelete;

		return;
	}

	node* temp = head;

	while(temp->next->data != val)
		temp = temp->next;

	node* todelete = temp->next;
	temp->next = temp->next->next;

	delete todelete;
}

void display(node* &head){
	node* temp = head;

	do{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	} while(temp != head);

	cout<<head->data<<endl;
}

int main(){

	node* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtHead(head, 6);
	
	display(head);

	deletion(head, 6);

	display(head);

	return 0;
}