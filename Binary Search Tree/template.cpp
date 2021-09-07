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

Node *inorderSuccessor(Node *root)
{
    Node *curr = root->right;
    while (curr->left)
        curr = curr->left;
    return curr;
}

Node *deleteBST(Node *root, int val)
{
    if (!root)
        return NULL;

    if (val < root->data)
        root->left = deleteBST(root->left, val);

    else if (val > root->data)
        root->right = deleteBST(root->right, val);

    else
    {
        if (!root->left)
        {
            Node *temp = temp->right;
            delete root;
            return temp;
        }

        else if (!root->right)
        {
            Node *temp = temp->left;
            delete root;
            return temp;
        }

        else
        {
            Node *temp = inorderSuccessor(root);
            swap(root->data, temp->data);
            root->right = deleteBST(root->right, val);
        }
    }

    return root;
}

int searchBST(Node *root, int val)
{
    if (!root)
        return -1;

    if (root->data == val)
        return root->data;

    if (val < root->data)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insertBST(root, 6);
    insertBST(root, 3);
    insertBST(root, 5);
    insertBST(root, 2);
    insertBST(root, 4);
    insertBST(root, 7);

    inorder(root);
    cout << endl;

    deleteBST(root, 3);
    inorder(root);

    // int val, found;
    // cin >> val;

    // found = searchBST(root, val);

    // if (found != -1)
    //     cout << "Key found: " << found << endl;
    // else
    //     cout << "Key not found" << endl;

    return 0;
}