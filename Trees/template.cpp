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

void preorder(node *root)
{
  if (!root)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  node *root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->right = new node(60);
  root->left->right->left = new node(70);
  root->right->left = new node(90);
  root->right->left->left = new node(100);
  root->right->left->right = new node(80);

  return 0;
}