#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node* prev;

	node(int val){
		data = val;
		next = NULL;
		prev = NULL;
	}
};

void insertAtHead(node* &head, int val){
	node* n = new node(val);

	n->next = head;

	if(head->prev != NULL)
		head->prev = n;

	head = n;
}

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
	n->prev = temp;
}

void deletion(node* &head, int val){
	if(head == NULL)
		return;

	if(head->data == val){
		node* temp = head;

		head = temp->next;

		delete temp;

		return;
	}

	node* temp = head;

	while(temp->data != val){
		temp = temp->next;
	}

	if(temp->next != NULL){
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}

	if(temp->next == NULL){
		temp->prev->next = NULL;
	}

	delete temp;
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

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);

	deletion(head, 4);

	display(head);

	return 0;
}