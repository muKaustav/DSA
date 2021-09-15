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

void diagonalTraversal(node *root)
{
    if (!root)
        return;

    map<int, vector<int>> m;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    int max_level = 0;

    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();

        max_level = max(max_level, p.second);

        m[p.second].push_back(p.first->data);

        if (p.first->left)
            q.push({p.first->left, p.second + 1});

        if (p.first->right)
            q.push({p.first->right, p.second});
    }
    
    for (int i = 0; i <= max_level; i++)
    {
        for (auto j : m[i])
        {
            cout << j << " ";
        }
    }
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

    diagonalTraversal(root);

    return 0;
}