#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *reverseLL2(Node *head, int l, int r)
{
    vector<int> v;

    Node *temp = head;

    for (int i = 0; i < l; i++)
        temp = temp->next;

    Node *node = temp;

    for (int i = l; i <= r; i++)
    {
        v.push_back(node->data);
        node = node->next;
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        temp->data = v[i];
        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    // 1, 4, 3, 2, 5

    Node *newHead = reverseLL2(head, 2, 4);
    display(newHead);

    return 0;
}