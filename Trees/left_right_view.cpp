#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> leftView(node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        int left = size - 1;

        while (size--)
        {
            node *temp = q.front();
            q.pop();

            if (size == left)
                ans.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}

vector<int> rightView(node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            node *temp = q.front();
            q.pop();

            if (size == 0)
                ans.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);

    vector<int> rightans = rightView(root);
    vector<int> leftans = leftView(root);

    for (int i = 0; i < rightans.size(); i++)
        cout << rightans[i] << " ";

    cout << endl;

    for (int i = 0; i < leftans.size(); i++)
        cout << leftans[i] << " ";

    return 0;
}