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
struct poly *mulpoly(struct poly *a, struct poly *b, struct poly *h3)
{
    struct poly *h = b;
    int rp, rc;
    while (a != NULL)
    {
        b = h;
        while (b != NULL)
        {
            rc = a->coef * b->coef;
            rp = a->power + b->power;
            h3 = createpoly(h3, rc, rp);
            b = b->next;
        }
        a = a->next;
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
struct poly *remo(struct poly *h, struct poly *t)
{
    struct poly *y = h;
    struct poly *g;
    while (y != t)
    {
        g = y;
        y = y->next;
    }
    g->next = y->next;
    y->next = NULL;
    free(y);
    y = NULL;
    return h;
}
struct poly *dupli(struct poly *h)
{
    struct poly *pt1, *pt2, *dup;
    pt1 = h;
    while (pt1 != NULL && pt1->next != NULL)
    {
        pt2 = pt1;
        while (pt2->next != NULL)
        {
            if (pt1->power == pt2->next->power)
            {
                pt1->coef = pt1->coef + pt2->next->coef;
                dup = pt2->next;
                h = remo(h, dup);
                pt2->next = pt2->next->next;
            }
            else
            {
                pt2 = pt2->next;
            }
        }
        pt1 = pt1->next;
    }
    return h;
}
int main()
{
    int i, c, p;
    printf("------Lets create and add multiply polynomials!------");
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
    h3 = mulpoly(h1, h2, h3);
    h3 = dupli(h3);
    printf("\nThe multiplication of given polynomials is:");
    printpoly(h3);
    return 0;
}
