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

void printLeftBoundary(node *root, vector<int> &v)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    v.push_back(root->data);

    if (root->left)
        printLeftBoundary(root->left, v);

    else
        printLeftBoundary(root->right, v);
}

void printRightBoundary(node *root, vector<int> &v)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    if (root->right)
        printRightBoundary(root->right, v);

    else
        printRightBoundary(root->left, v);

    v.push_back(root->data);
}

void printLeaves(node *root, vector<int> &v)
{
    if (!root)
        return;

    printLeaves(root->left, v);

    if (!root->left && !root->right)
        v.push_back(root->data);

    printLeaves(root->right, v);
}

vector<int> printBoundary(node *root)
{
    vector<int> ans;

    if (!root || !root->left && !root->right)
        return ans;

    ans.push_back(root->data);

    printLeftBoundary(root->left, ans);
    printLeaves(root, ans);
    printRightBoundary(root->right, ans);

    return ans;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->right = new node(60);
    root->left->right->left = new node(70);
    root->right->left = new node(90);
    root->right->left->left = new node(100);
    root->right->left->right = new node(80);

    vector<int> v = printBoundary(root);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}