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

int countNodes(node *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumOfNodes(node *root)
{
    if (root == NULL)
        return 0;

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main()
{

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);

    cout << countNodes(root) << endl;
    cout << sumOfNodes(root) << endl;

    return 0;
}