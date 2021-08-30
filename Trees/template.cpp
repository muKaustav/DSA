#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);
    root->right->left = new node(90);
    root->right->right = new node(100);

    // Preorder traversal
    cout << "Preorder traversal of binary tree is \n\n";
    preorder(root);

    return 0;
}