#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node (int val){
		data = val;
		next = NULL;
	}
};

node* insertAtTail(node* head, int val){
	node* temp = head;
	node* newNode = new node(val);

	while(temp != NULL){
		temp = temp->next;
	}

	temp->next = newNode;

	return head;
}

void display(node* head){
	node* temp = head;

	while(temp->next != NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}

	cout<<"NULL"; 
}

int main(){

	node* root = new node(0);
	insertAtTail(root, 1);
	insertAtTail(root, 2);

	display(root);

	return 0;
}