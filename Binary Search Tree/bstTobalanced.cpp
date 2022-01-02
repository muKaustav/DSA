#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

Node *insertBST(Node *root, int val) {
  if (!root)
    return new Node(val);

  if (val < root->data)
    root->left = insertBST(root->left, val);

  else
    root->right = insertBST(root->right, val);

  return root;
}

void inorder(Node *root) {
  if (!root)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(Node *root) {
  if (!root)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void getInorderNode(Node *root, vector<int> &inorder) {
  if (!root)
    return;

  getInorderNode(root->left, inorder);
  inorder.push_back(root->data);
  getInorderNode(root->right, inorder);
}

Node *sortedArrayToBST(vector<int> &inorder, int start, int end) {
  if (start > end)
    return NULL;

  int mid = (start + end) / 2;

  Node *root = new Node(inorder[mid]);
  root->left = sortedArrayToBST(inorder, start, mid - 1);
  root->right = sortedArrayToBST(inorder, mid + 1, end);

  return root;
}

Node *bstToBalanced(Node *root) {
  vector<int> inorder;
  getInorderNode(root, inorder);

  Node *newRoot = sortedArrayToBST(inorder, 0, inorder.size() - 1);

  return newRoot;
}

int main() {
  Node *root = new Node(4);
  root->left = new Node(3);
  root->left->left = new Node(2);
  root->left->left->left = new Node(1);
  root->right = new Node(5);
  root->right->right = new Node(6);
  root->right->right->right = new Node(7);

  Node *newRoot = bstToBalanced(root);

  preorder(newRoot);
  cout << endl;
  inorder(newRoot);

  return 0;
}