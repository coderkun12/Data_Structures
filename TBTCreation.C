#include <stdio.h>
#include <stdlib.h>
struct node
{
    int rf, lf, data;
    struct node *right, *left;
};
struct node *header = (struct node *)malloc(sizeof(struct node));
struct node *createe(struct node *root, int data)
{
    struct node *ptr = root;
    struct node *parent = NULL;
    while (ptr)
    {
        if (data == (ptr->data))
        {
            printf("Duplicate Key !\n");
            return root;
        }

        parent = ptr;

        if (data < ptr->data)
        {
            if (ptr->lf == 0)
                ptr = ptr->left;
            else
                break;
        }

        else
        {
            if (ptr->rf == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    // Create a new node
    struct node *value = new node;
    value->data = data;
    value->lf = 1;
    value->rf = 1;

    if (parent == NULL)
    {
        root = value;
        value->left = header;
        value->right = header;
    }
    else if (data < (parent->data))
    {
        value->left = parent->left;
        value->right = parent;
        parent->lf = 0;
        parent->left = value;
    }
    else
    {
        value->left = parent;
        value->right = parent->right;
        parent->rf = 0;
        parent->right = value;
    }
    return root;
}

struct node *inorderSuccessor(struct node *ptr)
{
    if (ptr->rf == 1)
    {
        return ptr->right;
    }
    ptr = ptr->right;
    while (ptr->lf == 0)
    {
        ptr = ptr->left;
    }
    return ptr;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    struct node *ptr = root;
    while (ptr->lf == 0)
    {
        ptr = ptr->left;
    }
    while (ptr != header)
    {
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        printf("\nTree Empty!");
    }
    else
    {
        while (root != header)
        {
            printf("%d ", root->data);
            if (root->lf == 0)
            {
                root = root->left;
            }
            else if (root->rf == 0)
            {
                root = root->right;
            }
            else
            {
                while (root != header && root->rf == 1)
                {
                    root = inorderSuccessor(root);
                }
                if (root != header)
                {
                    root = root->right;
                }
            }
        }
    }
}
void postorder(struct node *root)
{
    int arr[100];
    int a = 0;
    if (root == NULL)
    {
        printf("\nTree Empty!");
    }
    else
    {
        while (root != header)
        {
            arr[a] = root->data;
            a++;
            if (root->lf == 0)
            {
                root = root->left;
            }
            else if (root->rf == 0)
            {
                root = root->right;
            }
            else
            {
                while (root != header && root->rf == 1)
                {
                    root = inorderSuccessor(root);
                }
                if (root != header)
                {
                    root = root->right;
                }
            }
        }
    }
    a--;
    while (a >= 0)
    {
        printf("%d ", arr[a]);
        a--;
    }
}
int main()
{
    struct node *root = NULL;
    int opt, num;
    do
    {
        printf("\nEnter option number: 1. Add element to tree\t0. Stop adding");
        scanf("%d", &opt);
        if (opt == 1)
        {
            printf("\nEnter element:\t");
            scanf("%d", &num);
            root = createe(root, num);
        }
    } while (opt != 0);
    header->data = 32767;
    header->right = header;
    header->rf = 1;
    header->left = root;
    header->lf = 0;
    printf("\nEnter option number: 1. In-Order\t2. Pre-Order\t3.Post-Order\n");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
    {
        printf("\nThe In-order traversal is:\n");
        inorder(root);
        break;
    }
    case 2:
    {
        printf("\nThe Pre-order traversal is:\n");
        preorder(root);
        break;
    }
    case 3:
    {
        printf("\nThe Post-order traversal is:\n");
        postorder(root);
        break;
    }
    }
    return 0;
}