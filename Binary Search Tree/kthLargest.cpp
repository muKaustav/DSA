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

Node *insertBST(Node *root, int val)
{
  if (!root)
    return new Node(val);

  if (val < root->data)
    root->left = insertBST(root->left, val);

  else
    root->right = insertBST(root->right, val);

  return root;
}

void inorder(Node *root)
{
  if (!root)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int solve(Node *root, int k, int &count)
{
  if (!root)
    return INT_MIN;

  int val = solve(root->right, k, count);

  if (val != INT_MIN)
    return val;

  count++;

  if (count == k)
    return root->data;

  return solve(root->left, k, count);
}

int kthLargest(Node *root, int k)
{
  int count = 0;
  return solve(root, k, count);
}

int main()
{
  int keys[] = {20, 8, 4, 12, 10, 14, 22};
  Node *root = NULL;

  for (auto key : keys)
    root = insertBST(root, key);

  inorder(root);

  int k = 3;
  int count = 0;
  cout << "\n"
       << kthLargest(root, k) << endl;

  return 0;
}