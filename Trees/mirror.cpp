#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *mirror(struct node *root)
{
    if (root == NULL)
        return root;

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left)
        mirror(root->left);

    if (root->right)
        mirror(root->right);

    return root;
}

void printLevelOrder(struct node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    cout << endl;
}

int main()
{

    node *root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->left = new node(5);
    root->left->right->right = new node(6);

    printLevelOrder(root);
    mirror(root);
    printLevelOrder(root);

    return 0;
}