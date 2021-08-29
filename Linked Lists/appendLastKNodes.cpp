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

	n->next = head;
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
}

int length(node* head){
	if(head == NULL)
		return 0;

	else{
		return 1 + length(head->next);
	}
}

node* kappend(node* head, int k){
	node* temp = head;
	node* newTail;
	node* newHead;

	int count = 1, len = length(head);

	k %= len;

	if(len == k || k == 0)
		return head;

	while(temp->next != NULL){

		if(count == (len - k)){
			newTail = temp;
			newHead = temp->next;
		}

		temp = temp->next;
		count++;
	}

	newTail->next = NULL;
	temp->next = head;

	delete temp;

	return newHead;
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
	insertAtTail(head, 5);

	display(head);
	
	node* newHead = kappend(head, 7);

	display(newHead);

	return 0;
}