#include <stdio.h>
#include <stdlib.h>
#define bool int
struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};
struct sNode
{
    struct tNode *t;
    struct sNode *next;
};
void push(struct sNode **top_ref, struct tNode *t);
struct tNode *pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);
void postOrder(struct tNode *root)
{
    if (root == NULL)
    {
        return;
    }
    struct sNode *s = NULL;
    struct tNode *current = root;
    struct tNode *u, *y;
    bool done = 0;
    push(&s, root);
    do
    {
        while (current)
        {
            if (current->right)
            {
                push(&s, current->right);
            }
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);
        u = pop(&s);
        y = u;
        push(&s, u);
        if (current->right && current->right == y)
        {
            pop(&s);
            push(&s, current);
            current = current->right;
        }
        else
        {
            printf("%d ", current->data);
            current = NULL;
        }
    } while (!isEmpty(s));
    printf("%d", root->data);
}
void preOrder(struct tNode *root)
{
    if (root == NULL)
    {
        return;
    }
    struct sNode *s = NULL;
    struct tNode *current = root;
    bool done = 0;
    while (done != 1)
    {
        if (current != NULL)
        {
            printf("%d ", current->data);
            if (current->right)
            {
                push(&s, current->right);
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
void inOrder(struct tNode *root)
{
    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;
    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}
/*struct tNode *peek(struct sNode *topref)
{
    if (isEmpty(topref))
    {
        return NULL;
    }
    else
    {
        return;
    }
}*/
void push(struct sNode **top_ref, struct tNode *t)
{
    struct sNode *new_tNode =
        (struct sNode *)malloc(sizeof(struct sNode));

    if (new_tNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }
    new_tNode->t = t;
    new_tNode->next = (*top_ref);
    (*top_ref) = new_tNode;
}
bool isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}
struct tNode *pop(struct sNode **top_ref)
{
    struct tNode *res;
    struct sNode *top;
    if (isEmpty(*top_ref))
    {
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
struct tNode *newtNode(int data)
{
    struct tNode *tNode = (struct tNode *)
        malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return (tNode);
}
int main()
{
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
    printf("Inorder Sequence:\n");
    inOrder(root);
    printf("\nPreorder Sequence:\n");
    preOrder(root);
    printf("\nPostorder Sequence:\n");
    postOrder(root);
    return 0;
}