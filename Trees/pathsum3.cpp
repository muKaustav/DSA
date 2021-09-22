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

int pathsum(node *root, int sum)
{
    
}

int main()
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(-3);
    root->left->left = new node(3);
    root->left->right = new node(2);
    root->right->right = new node(11);
    root->left->left->left = new node(3);
    root->left->left->right = new node(-2);
    root->left->right->right = new node(1);

    return 0;
}