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

node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if (!root || root->data == p->data || root->data == q->data)
        return root;

    node *lnode = lowestCommonAncestor(root->left, p, q);
    node *rnode = lowestCommonAncestor(root->right, p, q);

    if (lnode != NULL && rnode != NULL)
        return root;

    else if (!rnode)
        return lnode;

    return rnode;
}

int main()
{
    node *root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    root->right->left = new node(0);
    root->right->right = new node(8);

    node *lca = lowestCommonAncestor(root, root->left, root->left->right->right);

    cout << lca->data << endl;

    return 0;
}