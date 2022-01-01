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

// heapsort
void heapify(Node *root, int n)
{
    int largest = root->data;
    Node *largest_node = root;

    Node *left = root->left;
    Node *right = root->right;

    if (left && left->data > largest)
    {
        largest = left->data;
        largest_node = left;
    }

    if (right && right->data > largest)
    {
        largest = right->data;
        largest_node = right;
    }

    if (largest != root->data)
    {
        swap(root->data, largest_node->data);
        heapify(largest_node, n);
    }
}

int main()
{
    // max heap
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(10);
    root->right->left = new Node(8);
    root->right->right = new Node(16);

    return 0;
}