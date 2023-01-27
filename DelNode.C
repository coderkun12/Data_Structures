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
struct bstnode *minVal(struct bstnode *root)
{
    struct bstnode *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct bstnode *DELETE(struct bstnode *root, int dat)
{
    if (root == NULL)
    {
        return root;
    }
    if (dat < root->data)
    {
        root->left = DELETE(root->left, dat);
    }
    else if (dat > root->data)
    {
        root->right = DELETE(root->right, dat);
    }
    else
    {
        // case 1: No child
        if (root->left && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // case 2:One child present
        else if (root->left == NULL)
        {
            struct bstnode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            struct bstnode *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        // case 3: both children present
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left == NULL)
            {
                struct bstnode *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                struct bstnode *temp = root->left;
                free(root);
                return temp;
            }
            struct bstnode *temp = minVal(root->right);
            root->data = temp->data;
            root->right = DELETE(root->right, root->right->data);
        }
    }
    return root;
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
    printf("before deletion:\n");
    traverse(root);
    printf("\nEnter the element you wish to delete:\n");
    scanf("%d", &t);
    root = DELETE(root, t);
    printf("after deletion:\n");
    traverse(root);
    return 0;
}