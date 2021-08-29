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

bool detectCycle(node* &head){
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow)
			return true;
	}
	return false;
}
	
void removeCycle(node* &head){

	if(detectCycle(head) == 0)
		return;

	node* slow = head;
	node* fast = head;

	do{
		slow = slow->next;
		fast = fast->next->next;
	} while(slow != fast);

	fast = head;

	while(slow->next != fast ->next){
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = NULL;
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

	node* newHead = rotateK(head, 0);

	display(newHead);
	
	return 0;
}