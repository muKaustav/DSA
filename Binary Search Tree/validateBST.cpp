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

void getInorder(Node *root, vector<int> &v)
{
    if (!root)
        return;

    getInorder(root->left, v);
    v.push_back(root->data);
    getInorder(root->right, v);
}

bool isValidBST(Node *root)
{
    vector<int> v;
    getInorder(root, v);

    for (int i = 1; i < v.size(); i++)
        if (v[i] <= v[i - 1])
            return false;

    return true;
}

int main()
{
    int keys[] = {20, 8, 4, 12, 10, 14, 22};
    Node *root = NULL;

    // Node *root = new Node(5);
    // root->left = new Node(4);
    // root->right = new Node(6);
    // root->right->left = new Node(3);
    // root->right->right = new Node(7);

    for (auto key : keys)
        root = insertBST(root, key);

    inorder(root);
    cout << endl;

    cout << isValidBST(root);

    return 0;
}