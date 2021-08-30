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

void getVerticalOrder(node *root, int hd, map<int, vector<int>> &m)
{
    if (!root)
        return;

    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

vector<vector<int>> verticalTraversal(node *root)
{
    solve(root, 0, 0);

    vector<vector<int>> ans;

    for (auto it1 : m)
    {
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(7);

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

    return 0;
}