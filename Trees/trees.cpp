#include <iostream>
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

void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    cout << node->data << " ";
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    //            1
    //          /   \
    //         /     \
    //       2        3
    //     /   \       
    //    /     \        
    //   4       5

    cout << "Postorder:" << endl;
    printPostorder(root);
    cout << endl
         << endl;

    cout << "Inorder:" << endl;
    printInorder(root);
    cout << endl
         << endl;

    cout << "Preorder:" << endl;
    printPreorder(root);
    cout << endl
         << endl;

    return 0;
}