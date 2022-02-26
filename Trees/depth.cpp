#include <iostream>
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

int maxDepth(Node *root)
{
	if (!root)
		return 0;

	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	// root->right->right->right = new Node(8);
	// root->right->right->right->left = new Node(9);

	cout << "height of tree " << maxDepth(root);

	return 0;
}