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

node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *nxt = NULL;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

node *addOne(node *head)
{
    head = reverse(head);

    node *curr = head;

    while (curr)
    {
        if (!curr->next && curr->data == 9)
        {
            curr->data = 1;
            node *temp = new node(0);
            temp->next = head;
            head = temp;
            curr = curr->next;
        }

        else if (curr->data == 9)
        {
            curr->data = 0;
            curr = curr->next;
        }

        else
        {
            curr->data += 1;
            break;
        }
    }

    return reverse(head);
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

int main()
{
    node *head = NULL;

    insertAtTail(head, 9);
    insertAtTail(head, 9);
    insertAtTail(head, 9);

    display(head);

    node *new_head = addOne(head);

    display(new_head);

    return 0;
}