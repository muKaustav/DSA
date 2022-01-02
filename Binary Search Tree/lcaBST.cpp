#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insertBST(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);

    else
        root->right = insertBST(root->right, val);

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *LCA(Node *root, int n1, int n2)
{
    if (!root || root->data == n1 || root->data == n2)
        return root;

    Node *lnode = LCA(root->left, n1, n2);
    Node *rnode = LCA(root->right, n1, n2);

    if (lnode && rnode)
        return root;

    else if (!lnode)
        return rnode;

    return lnode;
}

int main()
{
    int keys[] = {20, 8, 4, 12, 10, 14, 22};
    Node *root = NULL;

    for (auto key : keys)
        root = insertBST(root, key);

    int n1 = 4, n2 = 8;
    Node *lca = LCA(root, n1, n2);

    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->data << endl;

    else
        cout << "LCA of " << n1 << " and " << n2 << " is not found" << endl;

    return 0;
}