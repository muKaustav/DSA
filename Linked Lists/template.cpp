#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next, *mult;

	node(int val)
	{
		data = val;
		next = NULL;
		mult = NULL;
	}
};

void insertAtHead(node *&head, int val)
{
	node *n = new node(val);

	n->next = head;
	head = n;
}

void insertAtTail(node *&head, int val)
{
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

void connectMultiples(node *head)
{
	node *curr = head;

	while (curr)
	{
		int mult = curr->data;

		node *temp = curr->next;

		while (temp)
		{
			if (temp->data % mult == 0)
				curr->mult = temp;

			temp = temp->next;
		}
	}
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

	display(head);

	connectMultiples(head);

	return 0;
}