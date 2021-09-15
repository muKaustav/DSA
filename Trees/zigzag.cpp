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

vector<int> zigZagTraversal(node *root)
{
    vector<int> ans;

    
}

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

    vector<int> ans = zigZagTraversal(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}