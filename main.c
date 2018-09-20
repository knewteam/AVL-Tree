#include <stdio.h>

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
