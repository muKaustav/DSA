#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right, *next;

    Node(int val)
    {
        data = val;
        left = right = next = NULL;
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

void inorderNode(Node *root, vector<Node *> &v)
{
    if (!root)
        return;

    inorderNode(root->left, v);
    v.push_back(root);
    inorderNode(root->right, v);
}

vector<Node *> populateInorderSucc(Node *root)
{
    vector<Node *> v;
    inorderNode(root, v);

    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1)
            v[i]->next = new Node(-1);

        else
            v[i]->next = v[i + 1];
    }

    return v;
}

int main()
{

    int keys[] = {20, 8, 4, 12, 10, 14, 22};

    Node *root = NULL;

    for (auto key : keys)
        root = insertBST(root, key);

    inorder(root);
    cout << endl;

    vector<Node *> v = populateInorderSucc(root);

    for (auto node : v)
        cout << node->next->data << " ";

    return 0;
}