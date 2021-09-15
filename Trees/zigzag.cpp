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

<<<<<<< HEAD
vector<int> zigZagTraversal(node *root)
{
    vector<int> ans;

    
}

void preorder(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
=======
vector<vector<int>> zigzagLevelOrder(node *root)
{
    vector<vector<int>> ans;
    queue<node *> q;

    if (!root)
        return ans;

    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        vector<int> temp;
        int size = q.size();

        while (size--)
        {
            node *curr = q.front();
            temp.push_back(curr->data);
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        if (level == 0)
            reverse(temp.begin(), temp.end());

        ans.push_back(temp);
        level = !level;
    }

    return ans;
>>>>>>> c7b590fee7d4ab3758d25d6ea8016b29a8e1e27c
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

<<<<<<< HEAD
    vector<int> ans = zigZagTraversal(root);

    for (auto it : ans)
    {
        cout << it << " ";
=======
    vector<vector<int>> ans = zigzagLevelOrder(root);

    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
>>>>>>> c7b590fee7d4ab3758d25d6ea8016b29a8e1e27c
    }

    return 0;
}