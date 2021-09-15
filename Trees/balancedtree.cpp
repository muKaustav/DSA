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

int height(node *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

bool isBalanced(node *root)
{
    if (!root)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
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

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}