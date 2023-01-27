#include <stdio.h>
#include <stdlib.h>
struct tnode
{
    int data;
    struct tnode *right, *left;
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
// RECUSRION
/*struct tnode *mirror(struct tnode *root)
{
    struct tnode *f;
    struct tnode *current = root;
    if (current != NULL)
    {
        f = current->right;
        current->right = current->left;
        current->left = f;
        mirror(current->left);
        mirror(current->right);
    }
    return root;
}*/
struct snode
{
    struct tnode *Dat;
    struct snode *next;
};
struct snode *push(struct snode *s, struct tnode *link)
{
    struct snode *ne = (struct snode *)malloc(sizeof(struct snode));
    ne->Dat = link;
    if (s == NULL)
    {
        ne->next = NULL;
        s = ne;
        return s;
    }
    else
    {
        ne->next = s;
        s = ne;
        return s;
    }
}
bool isEmpty(struct snode *top)
{
    return (top == NULL) ? 1 : 0;
}
struct tnode *pop(struct snode **s)
{
    struct tnode *res;
    struct snode *top;
    if (isEmpty(*s))
    {
        getchar();
        exit(0);
    }
    else
    {
        top = *s;
        res = top->Dat;
        *s = top->next;
        free(top);
        return res;
    }
}
// USING STACK (NON-RECURSIVE)
void mirro(struct tnode **root)
{
    if (root == NULL)
    {
        return;
    }
    struct snode *s = NULL;
    struct tnode *i;
    struct tnode *current = *root;
    bool done = 0;
    while (done != 1)
    {
        if (current != NULL)
        {
            i = current->right;
            current->right = current->left;
            current->left = i;
            if (current->right)
            {
                s = push(s, current->right);
            }
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
            }
            else
            {
                done = 1;
            }
        }
    }
}
void traverse(struct tnode *root)
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
    printf("\nBefore Mirroring:\n");
    traverse(root);
    // root=mirror(root);
    mirro(&root);
    printf("\nAfter Mirroring:\n");
    traverse(root);
    return 0;
}