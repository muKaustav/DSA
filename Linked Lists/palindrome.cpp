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

node* reverse(node* head){
	node* pre = NULL;
	node* nex = NULL;
	while(head != NULL){
		nex = head->next;
		head->next = pre;
		pre = head;
		head = nex;
	}

	return pre;
}

bool isPalindrome(node* head){
	if(head==NULL || head->next==NULL) 
		return true;

	node *slow = head, *fast = head;

	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverse(slow->next);
	slow = slow->next;

	while(slow != NULL){
		if(head->val != slow->val){
			return false;
		}

		head = head->next;
		slow = slow->next;
	}

	return true;
} 

int main(){

	node* head = NULL;

	insertAtTail(head, 1);

	node* newHead = removeNthNode(head, 1);

	return 0;
}