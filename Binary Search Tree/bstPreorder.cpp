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

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
        return NULL;

    Node *root = NULL;

    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx += 1;

        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int preorderIdx = 0;
    int size = sizeof(preorder) / sizeof(preorder[0]);

    Node *root = constructBST(preorder, &preorderIdx, preorder[preorderIdx], INT_MIN, INT_MAX, size);

    inorder(root);

    return 0;
}