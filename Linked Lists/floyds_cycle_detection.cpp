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

void makeCycle(node* &head, int pos){
	node* temp = head;

	if(length(head) == pos){
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = temp;
		return;
	}

	node* startNode;

	int count = 1;

	while(temp->next != NULL){
		if(count == pos)
			startNode = temp;

		temp = temp->next;
		count++;
	}

	temp->next = startNode;
}

bool detectCyle(node* &head){
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
	node* slow = head;
	node* fast = head;

	do{
		slow = slow->next;
		fast = fast->next->next;
	} while(slow != fast);

	fast = head;

	if(fast == slow){
		while(slow->next != fast){
			slow = slow->next;
		}
	}
	else{
		while(slow->next != fast->next){
			slow = slow->next;
			fast = fast->next; 
		}
	}

	slow->next = NULL;
}	


int main(){

	node* head = NULL;

	insertAtTail(head, 7);
	insertAtTail(head, 58);
	insertAtTail(head, 36);
	insertAtTail(head, 34);
	insertAtTail(head, 16);
	
	display(head);
	
	makeCycle(head, 1);
	cout<<detectCyle(head)<<endl;

	removeCycle(head);

	display(head);

	cout<<detectCyle(head)<<endl;

	return 0;
}