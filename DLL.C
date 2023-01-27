#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next, *prev;
};
// TO ADD NODE AT NTH POSITION.
/*struct NODE *adn(struct NODE *head, int n, int pos)
{

    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = n;
    int i = 0;
    if (pos == 1)
    {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
        return head;
    }
    else
    {
        struct NODE *a = head;
        struct NODE *pre;
        while (i != pos)
        {
            pre = a;
            a = a->next;
            i++;
        }
        a->prev = new_node;
        new_node->next = a;
        new_node->prev = pre;
        pre->next = new_node;
        return head;
    }
}*/
// TO ADD NODE AT BEGINNING
struct NODE *adbeg(struct NODE *head, int n)
{
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = n;
    new_node->prev = NULL;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        return head;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return head;
    }
}
// TO ADD NODE AT END OF LL.
/*struct NODE *append(struct NODE *head, int n)
{
    struct NODE *last = (head);
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = n;
    new_node->next = NULL;
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return head;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return head;
}*/
// TO DELETE A NODE FROM END OF LIST
/*struct NODE *delend(struct NODE *head)
{
    struct NODE *po;
    struct NODE *yo = head;
    while (yo->next != NULL)
    {
        po = yo;
        yo = yo->next;
    }
    po->next = NULL;
    yo->prev = NULL;
    free(yo);
    yo = NULL;
    return head;
}*/
// TO DELETE A NODE FROM BEGINING
/*struct NODE *delbeg(struct NODE *head)
{
    struct NODE *y = head;
    head = head->next;
    head->prev = NULL;
    y->next = NULL;
    free(y);
    y = NULL;
    return head;
}*/
// TO DELETE NODE FROM NTH POSITION
struct NODE *deln(struct NODE *head, int pos)
{
    int i = 1;
    struct NODE *temp1;
    if (pos == 1)
    {
        temp1 = head;
        head = head->next;
        head->prev = NULL;
        temp1->next = NULL;
        free(temp1);
        temp1 = NULL;
        return head;
    }
    else
    {
        temp1 = head;
        struct NODE *temp2, *o;
        while (i != pos)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            i++;
        }
        o = temp1->next;
        temp2->next = o;
        o->prev = temp2;
        temp1->next = NULL;
        temp1->prev = NULL;
        free(temp1);
        temp1 = NULL;
        return head;
    }
}
void printlist(struct NODE *h)
{
    printf("\n");
    while (h != NULL)
    {
        printf("%d\t", h->data);
        h = h->next;
    }
}
void printrev(struct NODE *h)
{
    printf("\n");
    while (h->next != NULL)
    {
        h = h->next;
    }
    while (h != NULL)
    {
        printf("%d\t", h->data);
        h = h->prev;
    }
}
int main()
{
    struct NODE *head = NULL;

    int num, pos;
    printf("Enter a number to add to LL:");
    scanf("%d", &num);
    head = adbeg(head, num);
    // head = append(head, num);
    printf("Enter a number to add to LL:");
    scanf("%d", &num);
    head = adbeg(head, num);
    printf("Enter a number to add to LL:");
    scanf("%d", &num);
    head = adbeg(head, num);
    printf("Enter a number to add to LL:");
    scanf("%d", &num);
    head = adbeg(head, num);
    // head = append(head, num);
    printlist(head);
    printf("\nEnter position you wish to delete:\n");
    scanf("%d", &pos);
    head = deln(head, pos);
    // head = delend(head);
    // head = delbeg(head);
    // printf("\nEnter position where you wish to add element:");
    // scanf("%d", &pos);
    // printf("Enter a number to add to LL:");
    // scanf("%d", &num);
    // head = adn(head, num, pos);
    printf("\nThe list is:");
    printlist(head);
    printf("\nThe list in reversed order is:");
    printrev(head);
    free(head);
    return 0;
}