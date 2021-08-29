#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int val)
	{
		data = val;
		next = NULL;
	}
};

void insertAtTail(node *&head, int val){
	node *n = new node(val);

	if (head == NULL)
	{
		head = n;
		return;
	}

	node *temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = n;
}

int length(node* head){
	if(head == NULL)
		return 0;

	else
		return 1 + length(head->next);
}

node* removeNthNode(node* head, int n){
	int len = length(head);

	if(n == len)
		return head->next;

	else{
		int count = len - n;

		node* ptr1;
		node* ptr2 = head;

		while(count){
			ptr1 = ptr2;
			ptr2 = ptr2->next;
			count--;
		}

		ptr1->next = ptr2->next;
	}

	return head;
}

void display(node *head){
	node *temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << "NULL" << endl;
}

int main(){

	node* head = NULL;

	insertAtTail(head, 1);
	// insertAtTail(head, 2);

	node* newHead = removeNthNode(head, 1);

	display(newHead);

	return 0;
}