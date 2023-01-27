#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
// To add a node before initial node!
void add_node(struct NODE **head, int num)
{
    struct NODE *new_head;
    new_head = (struct NODE *)malloc(sizeof(struct NODE));
    new_head->data = num;
    new_head->next = (*head);
    (*head) = new_head;
}
/*void add_node(struct NODE *previous, int num,int pos)
{
    int i=1;
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = num;
    if (i==1)
    {
        previous=new_node;
        previous->next=NULL;
        return;
    }
    else{
    struct NODE* jo1=previous;
    struct NODE* jo2;
    while(i!=pos)
    {
        jo2=jo1;
        jo1=jo1->next;
    }
    new_node->next =jo1;
    jo2->next = new_node;
    }
}*/
// TO ADD NODE AT THE END
/*void add_node(struct NODE **head, int num)
{
    struct NODE *new_head;
    new_head = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *last = *head;
    new_head->data = num;
    new_head->next = NULL;
    if (*head == NULL)
    {
        *head = new_head;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_head;
    return;
}*/
// TO DELTE NODE AT BEGINING
/*struct NODE *delpre(struct NODE *head)
{
    if (head == NULL)
    {
        printf("\nList already empty!\n");
    }
    else
    {
        struct NODE *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}*/
// TO DELETE NODE FROM IN BETWEEN
/*struct NODE *dele(struct NODE *head, int n)
{
    int i;
    struct NODE *temp2;
    struct NODE *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
        return head;
    }
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}*/
// TO DELETE NODE WHICH IS AT END.
/*struct NODE *delb(struct NODE *head)
{
    if (head == NULL)
    {
        printf("\nList already empty!\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct NODE *temp = head;
        struct NODE *temp2 = head;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}*/

void printlist(struct NODE *n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}
int main()
{
    int option, number, num;
    struct NODE *head = NULL;
    do
    {
        printf("\nDo you wish to add more nodes before the initial node. Press 1. Else 0\n");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("\nEnter a number to be added to list:\t");
            scanf("%d", &number);
            add_node(&head, number);
        }
    } while (option != 0);
    printf("\nThe elements in linked list are:\n");
    printlist(head);
    free(head);
    return 0;
}