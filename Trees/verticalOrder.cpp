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
    vector<vector<int>> ans;

    map<int, vector<int>> m;

    getVerticalOrder(root, 0, m);

    for (auto i : m)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);
    root->right->left = new node(90);
    root->right->right = new node(100);

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