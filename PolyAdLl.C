#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int coef, power;
    struct poly *next;
};
struct poly *createpoly(struct poly *head, int c, int p)
{
    struct poly *new_node = (struct poly *)malloc(sizeof(struct poly));
    if (head == NULL)
    {
        new_node->coef = c;

        new_node->power = p;
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else
    {
        new_node->coef = c;
        new_node->power = p;
        struct poly *a = head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        a->next = new_node;
        new_node->next = NULL;
        return head;
    }
}
struct poly *addpoly(struct poly *a, struct poly *b, struct poly *h3)
{
    int c1, c2, p1, p2, res;
    while (a != NULL && b != NULL)
    {
        if (a->power == b->power)
        {
            res = a->coef + b->coef;
            h3 = createpoly(h3, res, a->power);
            a = a->next;
            b = b->next;
        }
        else
        {
            if (a->power > b->power)
            {
                h3 = createpoly(h3, a->coef, a->power);
                a = a->next;
            }
            else
            {
                h3 = createpoly(h3, b->coef, b->power);
                b = b->next;
            }
        }
    }
    while (a != NULL)
    {
        h3 = createpoly(h3, a->coef, a->power);
        a = a->next;
    }
    while (b != NULL)
    {
        h3 = createpoly(h3, b->coef, b->power);
        b = b->next;
    }
    return h3;
}
void printpoly(struct poly *h)
{
    printf("\n");
    printf("(%d x^%d)", h->coef, h->power);
    h = h->next;
    while (h != NULL)
    {
        printf("+ (%d x^%d)", h->coef, h->power);
        h = h->next;
    }
}
int main()
{
    int i, c, p;
    printf("------Lets create and add two polynomials!------");
    struct poly *h1 = NULL;
    struct poly *h2 = NULL;
    struct poly *h3 = NULL;
    int num;
    printf("\nEnter number of terms in polynomial 1:\t");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        printf("\nEnter the coefficient of term %d:\t", i);
        scanf("%d", &c);
        printf("\nEnter the power of term %d:\t", i);
        scanf("%d", &p);
        h1 = createpoly(h1, c, p);
    }
    printf("\nEnter number of terms in polynomial 2:\t");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        printf("\nEnter the coefficient of term %d:\t", i);
        scanf("%d", &c);
        printf("\nEnter the power of term %d:\t", i);
        scanf("%d", &p);
        h2 = createpoly(h2, c, p);
    }
    h3 = addpoly(h1, h2, h3);
    printf("\nThe addition of given polynomials is:");
    printpoly(h3);
    return 0;
}
