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

void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    cout << node->data << " ";
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}

void printLevelOrder(struct node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);

    int size;

    while (!q.empty())
    {
        size = q.size();

        while (size--)
        {
            node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);

    printLevelOrder(root);

    // cout << "Postorder:" << endl;
    // printPostorder(root);
    // cout << endl
    //      << endl;

    // cout << "Inorder:" << endl;
    // printInorder(root);
    // cout << endl
    //      << endl;

    // cout << "Preorder:" << endl;
    // printPreorder(root);
    // cout << endl
    //      << endl;

    return 0;
}