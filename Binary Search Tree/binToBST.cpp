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

void getInorderNode(Node *root, vector<int> &inorder)
{
    if (!root)
        return;

    getInorderNode(root->left, inorder);
    inorder.push_back(root->data);
    getInorderNode(root->right, inorder);
}

void traverse(Node *root, vector<int> &inorder, int &i)
{
    if (!root)
        return;

    traverse(root->left, inorder, i);
    root->data = inorder[i++];
    traverse(root->right, inorder, i);
}

Node *binToBST(Node *root)
{
    vector<int> inorder;
    getInorderNode(root, inorder);

    sort(inorder.begin(), inorder.end());

    int i = 0;
    traverse(root, inorder, i);

    return root;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(4);

    inorder(root);
    cout << endl;

    Node *newRoot = binToBST(root);
    inorder(newRoot);

    return 0;
}