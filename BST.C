#include <stdio.h>
#include <stdlib.h>
struct bstnode
{
    int data;
    struct bstnode *right, *left;
};
struct bstnode *new_node(int data)
{
    struct bstnode *nn = (struct bstnode *)malloc(sizeof(struct bstnode));
    nn->left = NULL;
    nn->right = NULL;
    nn->data = data;
    return nn;
}
struct bstnode *insert(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        root = new_node(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
int search(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == data)
    {
        return 1;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
void traverse(struct bstnode *root)
{
    if (root != NULL)
    {
        traverse(root->left);
        printf("%d\t", root->data);
        traverse(root->right);
    }
}
int main()
{
    int t, opt;
    struct bstnode *root = NULL;
    do
    {
        printf("\nEnter option number: 1. Enter element\t0. Stop adding");
        scanf("%d", &opt);
        if (opt == 1)
        {
            printf("\nEnter the element: ");
            scanf("%d", &t);
            root = insert(root, t);
        }
    } while (opt != 0);
    printf("\nEnter the number you wish to find in the tree: ");
    scanf("%d", &t);
    search(root, t);
    if (t == 1)
    {
        printf("Found number");
    }
    else
    {
        printf("Number not found!");
    }
    printf("\nThe elements in the tree at given moment is:\n");
    traverse(root);
    return 0;
}