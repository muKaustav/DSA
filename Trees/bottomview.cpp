#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

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

void getBottomView(node *root, map<int, pair<int, int>> &m, int hd, int l)
{
    if (!root)
        return;

    if (m.count(hd) == 0 || m[hd].second <= l)
        m[hd] = make_pair(root->data, l);

    getBottomView(root->left, m, hd - 1, l + 1);
    getBottomView(root->right, m, hd + 1, l + 1);
}

vi bottomView(node *root)
{
    vi ans;

    if (!root)
        return ans;

    map<int, pair<int, int>> m;

    getBottomView(root, m, 0, 0);

    for (auto it : m)
    {
        ans.push_back(it.second.first);
    }

    return ans;
}

int main()
{
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(5);
    root->left->right = new node(3);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right->right = new node(25);

    vi ans = bottomView(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}

// 14 14 3 N 8 8 12 N 6 17 3 N 1 11 10 N 6 6 13 N 10 17 7 N 11 7
