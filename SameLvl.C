#include <stdio.h>
#include <stdlib.h>
int f = 0;
struct tnode
{
    int data;
    struct tnode *left, *right;
};
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
        printf("");
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
bool isEmpty(struct qnode *front)
{
    return (front == NULL);
}
// NON RECURSIVE
void printlevel(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    int gg;
    gg = 0;
    struct qnode *s = NULL;
    struct tnode *s1;
    s1 = root;
    do
    {
        while (s1 != NULL)
        {
            printf("%d ", s1->data);

            if (s1->left != NULL)
            {
                s = addq(s, s1->left);
            }
            if (s1->right != NULL)
            {
                s = addq(s, s1->right);
            }
            s1 = delq(&s);
            if (gg % 2 == 0)
            {
                printf("\n");
            }
            gg++;
        }
    } while (!isEmpty(s));
}
// RECURSIVE
/*int height(struct tnode *node)
{
    if (node == NULL)
        return 0;
    else
    {

int lheight = height(node->left);
int rheight = height(node->right);

if (lheight > rheight)
{
    return (lheight + 1);
}
else
{
    return (rheight + 1);
}
}
}
void printgiven(struct tnode *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printgiven(root->left, level - 1);
        printgiven(root->right, level - 1);
    }
}
void samlvl(struct tnode *root)
{
    int h = height(root);
    int i;
    for (i = 0; i <= h; i++)
    {
        printgiven(root, i);
        printf("\n");
    }
}
*/
int main()
{
    int t, opt, he;
    he = 0;
    struct tnode *root = NULL;
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
    printlevel(root);
}
