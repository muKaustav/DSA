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

Node *minValueNode(Node *root)
{
    Node *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *maxValueNode(Node *root)
{
    Node *current = root;

    while (current->right != NULL)
        current = current->right;

    return current;
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

    Node *min = minValueNode(root);
    cout << "Min value is " << min->data << endl;

    Node *max = maxValueNode(root);
    cout << "Max value is " << max->data << endl;

    return 0;
}