#include <stdio.h>
#include <stdlib.h>

struct Node *deleteNode(struct Node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

typedef struct Node
{
    int value;
    struct Node_ *left;
    struct Node_ *right;
    struct Node_ *father;
} node;

node *insert(int info, node *tree); // insert in a tree

int main(void)
{
    return 0;
}

node *insert(int info, node *tree) // insert in a tree
{

    if (tree == NULL)
    {
        tree = CriarArvore(info); // This function needs to be created
    }
    else
    {
        if (info > tree->value)
        {
            tree->right = insert(info, tree->right);
        }
        else
        {
            tree->left = insert(info, tree->left);
        }
    }
    return tree;
}
