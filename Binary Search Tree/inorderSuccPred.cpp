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

void inorderSuccessor(Node *root, Node *&successor, int key)
{
    if (!root)
    {
        successor = NULL;
        return;
    }

    if (root->data == key)
    {
        if (root->right)
        {
            successor = root->right;

            while (successor->left)
                successor = successor->left;
        }
    }

    else if (root->data > key)
    {
        successor = root;
        inorderSuccessor(root->left, successor, key);
    }

    else
        inorderSuccessor(root->right, successor, key);
}

void inorderPredecessor(Node *root, Node *&predecessor, int key)
{
    if (!root)
    {
        predecessor = NULL;
        return;
    }

    if (root->data == key)
    {
        if (root->left)
        {
            predecessor = root->left;

            while (predecessor->right)
                predecessor = predecessor->right;
        }
    }

    else if (root->data > key)
        inorderPredecessor(root->left, predecessor, key);

    else
    {
        predecessor = root;
        inorderPredecessor(root->right, predecessor, key);
    }
}

int main()
{
    int keys[] = {20, 8, 4, 12, 10, 14, 22};

    Node *root = NULL;

    for (auto key : keys)
        root = insertBST(root, key);

    inorder(root);
    cout << endl;

    for (auto i : keys)
    {
        Node *successor = NULL;
        Node *predecessor = NULL;

        inorderSuccessor(root, successor, i);
        inorderPredecessor(root, predecessor, i);

        cout << "\nInorder Successor of " << i << " is " << (successor ? successor->data : -1) << endl;
        cout << "Inorder Predecessor of " << i << " is " << (predecessor ? predecessor->data : -1) << endl;
    }

    return 0;
}