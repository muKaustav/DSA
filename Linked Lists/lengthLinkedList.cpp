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

void display(node* head){
	node* temp = head;

	while(temp != NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}

	cout<<"NULL"<<endl;
}

int length(node* head){
	if(head == NULL)
		return 0;
	else{
		return 1 + length(head->next);
	}
}

int main(){

	node* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	insertAtTail(head, 7);
	insertAtTail(head, 8);
	insertAtTail(head, 9);

	display(head);

	cout<<length(head);

	return 0;
}