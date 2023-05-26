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

void printLeftBoundary(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        printLeftBoundary(root->left, ans);
    }

    else if (root->right)
    {
        ans.push_back(root->data);
        printLeftBoundary(root->right, ans);
    }
}

void printRightBoundary(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->right)
    {
        printRightBoundary(root->right, ans);
        ans.push_back(root->data);
    }

    else if (root->left)
    {
        printRightBoundary(root->left, ans);
        ans.push_back(root->data);
    }
}

void printLeaf(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    printLeaf(root->left, ans);

    if (!root->right && !root->left)
        ans.push_back(root->data);

    printLeaf(root->right, ans);
}

vector<int> printBoundary(Node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    ans.push_back(root->data);

    if (!root->left && !root->right)
        return ans;

    printLeftBoundary(root->left, ans);
    printLeaf(root, ans);
    printRightBoundary(root->right, ans);

    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(60);
    root->left->right->left = new Node(70);
    root->right->left = new Node(90);
    root->right->left->left = new Node(100);
    root->right->left->right = new Node(80);

    vector<int> v = printBoundary(root);

    for (auto i : v)
        cout << i << " ";

    return 0;
}