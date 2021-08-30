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

node *lowestCommonAncestor(node *root, int n1, int n2)
{
    if (!root || root->data == n1 || root->data == n2)
        return root;

    node *lnode = lowestCommonAncestor(root->left, n1, n2);
    node *rnode = lowestCommonAncestor(root->right, n1, n2);

    if (lnode && rnode)
        return root;

    return lnode ? lnode : rnode;
}

int solve(node *root, int val)
{
    if (!root)
        return 0;

    if (root->data == val)
        return 1;

    int l = solve(root->left, val);
    int r = solve(root->right, val);

    if (!l && !r)
        return 0;

    else
        return l + r + 1;
}

int findDist(node *root, int a, int b)
{
    node *lca = lowestCommonAncestor(root, a, b);

    int distA = solve(lca, a);
    int distB = solve(lca, b);

    return distA + distB - 2;
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

    cout << findDist(root, 2, 1);

    return 0;
}