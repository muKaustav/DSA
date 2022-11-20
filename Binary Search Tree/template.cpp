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

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorderArr(Node *root, vector<int> &sortedArr)
{
    if (!root)
        return;

    inorderArr(root->left, sortedArr);
    sortedArr.push_back(root->data);
    inorderArr(root->right, sortedArr);
}

int main()
{
    int keys[] = {20, 8, 4, 12, 10, 14, 22};
    Node *root = NULL;

    for (auto key : keys)
        root = insertBST(root, key);

    vector<int> sortedArr;

    inorderArr(root, sortedArr);

    for (auto it : sortedArr)
        cout << it << " ";

    return 0;
}