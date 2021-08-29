#include <iostream>
using namespace std;

class node
{
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

node* addTwoNumbers(node* l1, node* l2){
	node* result = new node(0);
	node* temp = result;

	int carry = 0;

	while(l1 != NULL || l2 != NULL){
		int num1, num2, sum;

		num1 = (l1 != NULL) ? l1->data : 0;
		num2 = (l2 != NULL) ? l2->data : 0;

		sum = num1 + num2 + carry;
		carry = sum / 10;

		temp->next = new node(sum % 10);
		temp = temp->next;

		if(l1 != NULL)
			l1 = l1->next;

		if(l2 != NULL)
			l2 = l2->next;
	}

	if(carry > 0)
		temp->next = new node(carry);

	return result->next;
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

	node *head1 = NULL;
	node *head2 = NULL;
	node *newhead;

	insertAtTail(head1, 2);
	insertAtTail(head1, 4);
	insertAtTail(head1, 3);

	insertAtTail(head2, 5);
	insertAtTail(head2, 6);
	insertAtTail(head2, 4);	

	newhead = addTwoNumbers(head1, head2);

	display(newhead);

	return 0;
}