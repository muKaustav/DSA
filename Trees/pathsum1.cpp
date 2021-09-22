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

bool pathsum(node *root, int sum)
{
    if (!root)
        return false;

    if (root->data == sum && !root->left && !root->right)
        return true;

    return pathsum(root->left, sum - root->data) || pathsum(root->right, sum - root->data);
}

int main()
{
    node *root = new node(5);
    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(11);
    root->left->left->left = new node(7);
    root->left->left->right = new node(2);
    root->right->left = new node(13);
    root->right->right = new node(4);
    root->right->right->left = new node(5);
    root->right->right->right = new node(1);

    if (pathsum(root, 22))
        cout << "Path exists";
    else
        cout << "Path doesn't exist";

    return 0;
}