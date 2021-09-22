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

void pathSumUtil(node *root, int targetSum, vector<int> &path, vector<vector<int>> &ans)
{
    if (!root)
        return;

    path.push_back(root->data);

    targetSum -= root->data;

    if (!root->left && !root->right)
    {
        if (targetSum == 0)
            ans.push_back(path);
    }

    pathSumUtil(root->left, targetSum, path, ans);
    pathSumUtil(root->right, targetSum, path, ans);

    path.pop_back();
}

vector<vector<int>> pathSum(node *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> path;

    pathSumUtil(root, targetSum, path, ans);

    return ans;
}

int main()
{
    node *root = new node(5);
    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(11);
    root->left->left->left = new node(7);
    root->left->left->right = new node(2);
    root->right->left = new node(13);
    root->right->right = new node(4);
    root->right->right->left = new node(5);
    root->right->right->right = new node(1);

    vector<vector<int>> ans = pathSum(root, 22);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}