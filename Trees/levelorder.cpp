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

void printLevelOrder(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *node = q.front();
        q.pop();

        if (node)
        {
            cout << node->data << " ";
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        else if (!q.empty())
            q.push(NULL);
    }
}

int sumAtK(node *root, int k)
{
    if (root == NULL)
        return -1;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    int sum = 0;
    int level = 0;

    while (!q.empty())
    {
        node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == k)
                sum += node->data;

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }

        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int main()
{

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);

    printLevelOrder(root);

    return 0;
}