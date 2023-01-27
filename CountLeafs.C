#include <stdio.h>
#include <stdlib.h>
static int count = 0;
struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};
struct qnode
{
    struct tnode *dat;
    struct qnode *next;
};
struct qnode *addq(struct qnode *rear, struct tnode *dat)
{
    struct qnode *new_node = (struct qnode *)malloc(sizeof(struct qnode));
    new_node->dat = dat;
    if (rear == NULL)
    {

        new_node->next = NULL;
        rear = new_node;
        return rear;
    }
    else
    {

        struct qnode *b = rear;
        while (b->next != NULL)
        {
            b = b->next;
        }
        b->next = new_node;
        new_node->next = NULL;
        return rear;
    }
}
struct tnode *delq(struct qnode **front)
{
    if (*front == NULL)
    {
        printf("\n");
    }
    else
    {
        struct qnode *s = *front;
        struct tnode *j = s->dat;
        *front = s->next;
        s->next = NULL;
        free(s);
        s = NULL;
        return j;
    }
}
int isEmpty(struct qnode *front)
{
    if (front == NULL)
    {
        return 0;
    }
}
int countleaf(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    struct tnode *y = root;
    struct qnode *s = NULL;
    s = addq(s, root);
    while (isEmpty(s) != 0)
    {
        y = delq(&s);
        if (y->left != NULL)
        {
            s = addq(s, y->left);
        }
        if (y->right != NULL)
        {
            s = addq(s, y->right);
        }
        if (y->left == NULL && y->right == NULL)
        {
            count = count + 1;
        }
    }
    return count;
}
/*unsigned int getLeafCount(struct tnode *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left) +
               getLeafCount(node->right);
}*/
struct tnode *new_node(int data)
{
    struct tnode *nn = (struct tnode *)malloc(sizeof(struct tnode));
    nn->left = NULL;
    nn->right = NULL;
    nn->data = data;
    return nn;
}
struct tnode *insert(struct tnode *root, int data)
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
int main()
{
    struct tnode *root = NULL;
    int t, opt;
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
    int jo = countleaf(root);
    printf("Leaf count of the tree is: %d", jo);
    return 0;
}
