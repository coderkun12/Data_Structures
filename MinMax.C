#include <stdio.h>
#include <stdlib.h>
struct tnode
{
    int data;
    struct tnode *right, *left;
};
struct tnode *create(struct tnode *root, int data)
{
    struct tnode *h = (struct tnode *)malloc(sizeof(struct tnode));
    h->data = data;
    if (root == NULL)
    {
        h->left = NULL;
        h->right = NULL;
        root = h;
        return root;
    }
    else
    {
        if (data > root->data)
        {
            root->right = create(root->right, data);
        }
        else
        {
            root->left = create(root->left, data);
        }
        return root;
    }
}
int findMin(struct tnode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int findMax(struct tnode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int main()
{
    int t, opt, h1, h2;
    struct tnode *root = NULL;
    do
    {
        printf("\nEnter option number: 1. Enter element\t0. Stop adding");
        scanf("%d", &opt);
        if (opt == 1)
        {
            printf("\nEnter the element: ");
            scanf("%d", &t);
            root = create(root, t);
        }
    } while (opt != 0);
    printf("\nThe greatest number is:\t");
    printf("%d", findMax(root));
    printf("\nThe smallest number is:\t");
    printf("%d", findMin(root));
    return 0;
}