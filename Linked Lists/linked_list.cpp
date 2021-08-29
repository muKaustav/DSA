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

void insertAtHead(node *&head, int val){
	node *n = new node(val);

	n->next = head;
	head = n;
}

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

void insert(node *&head, int pos, int val){

	if (pos == 0)
	{
		insertAtHead(head, val);
		return;
	}

	node *n = new node(val);

	node *temp = head;

	int cnt = 0;

	while (cnt < (pos - 1))
	{
		temp = temp->next;
		cnt++;
	}

	n->next = temp->next;
	temp->next = n;
}

void deletion(node *&head, int val){

	if (head == NULL)
		return;

	if (head->next == NULL){
		node *todelete = head;

		head = head->next;

		delete todelete;

		return;
	}

	if (head->data == val){
		node *temp = head;

		head = head->next;

		delete temp;

		return;
	}

	node *temp = head;

	while (temp->next->data != val)
		temp = temp->next;

	node *todelete = temp->next;
	temp->next = temp->next->next;

	delete todelete;
}

// what is the difference between &head and head wrt to program?

node *reverse(node *head){
	node *prevptr = NULL;
	node *currptr = head;
	node *nextptr;

	while (currptr != NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;

		prevptr = currptr;
		currptr = nextptr;
	}
	return prevptr;
}

// clarify on the call stack

node *recursiveReverse(node *head){
	if (head == NULL || head->next == NULL)
		return head;

	node *newHead = recursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;

	return newHead;
}

int searchPos(node *head, int key){
	node *temp = head;

	int pos = 0;

	while (temp->next != NULL)
	{
		if (temp->data == key)
		{
			return pos;
		}
		temp = temp->next;
		pos++;
	}

	return -1;
}

node *reversek(node *&head, int k){
	node *prevptr = NULL;
	node *currptr = head;
	node *nextptr;

	int c = 0;

	while (currptr != NULL && c < k)
	{
		nextptr = currptr->next;
		currptr->next = prevptr;

		prevptr = currptr;
		currptr = nextptr;

		c++;
	}

	if (nextptr != NULL)
		head->next = reversek(nextptr, k);

	return prevptr;
}

bool search(node* head, int key){
	node* temp = head;

	while(temp->next != NULL){
		if(temp->data == key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void display(node *head)
{
	node *temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << "NULL" << endl;
}

int main()
{

	node *head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	insertAtTail(head, 7);
	insertAtTail(head, 8);
	insertAtTail(head, 9);
	insert(head, 0, 100);
	insert(head, 4, 200);

	display(head);

	node *newHead = recursiveReverse(head);

	display(newHead);

	return 0;
}