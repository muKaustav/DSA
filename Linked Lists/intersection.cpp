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

int length(node* &head){
	if(head == NULL)
		return 0;
	else
		return 1 + length(head->next);
}

void intersect(node* &head1, node* &head2, int pos){
	node* temp1 = head1;
	node* temp2 = head2;

	pos--;

	while(pos--)
		temp1 = temp1->next;
	
	while(temp2->next != NULL)
		temp2 = temp2->next;

	temp2->next = temp1;
}

int intersection(node* &head1, node* &head2){
	int len1 = length(head1);
	int len2 = length(head2);
	
	int d = 0;

	node* ptr1;
	node* ptr2;

	if(len1 > len2){
		d = len1 - len2;
		ptr1 = head1;
		ptr2 = head2;
	}

	else{
		d = len2 - len1;
		ptr1 = head2;
		ptr2 = head1;
	}

	while(d){
		ptr1 = ptr1->next;

		if(ptr1 == NULL)
			return -1;

		d--;
	}

	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1 == ptr2)
			return ptr1->data;

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	return -1;
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

	node* head1 = NULL;
	node* head2 = NULL;

	insertAtTail(head1, 1);
	insertAtTail(head1, 2);
	insertAtTail(head1, 3);
	insertAtTail(head1, 4);
	insertAtTail(head1, 5);
	insertAtTail(head1, 6);
	insertAtTail(head1, 7);

	insertAtTail(head2, 8);
	insertAtTail(head2, 9);
	insertAtTail(head2, 10);
	insertAtTail(head2, 11);

	intersect(head1, head2, 4);

	display(head1);
	display(head2);

	cout<<intersection(head1, head2)<<endl;

	return 0;
}