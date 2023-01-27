#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
void append(struct NODE **head, int num)
{
    struct NODE *last = (*head);
    struct NODE *New_node = (struct NODE *)malloc(sizeof(struct NODE));
    New_node->data = num;
    New_node->next = NULL;
    if (*head == NULL)
    {
        *head = New_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = New_node;
    return;
}
void pre(struct NODE **head, int num)
{
    struct NODE *New_node = (struct NODE *)malloc(sizeof(struct NODE));
    New_node->data = num;
    New_node->next = (*head);
    *head = New_node;
}
void insert(struct NODE *previous, int num)
{
    if (previous == NULL)
    {
        printf("\nThe previous cant be a NULL!");
        return;
    }
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->data = num;
    new_node->next = previous->next;
    previous->next = new_node;
}
void printlist(struct NODE *head)
{
    while (head->next != NULL)
    {
        printf("\n%d", head->data);
        head = head->next;
    }
}
int main()
{
    struct NODE *head = NULL;
    int num, option;
    do
    {
        printf("\nEnter the option you wish to do:\n1. Addd node at begining\n2. Add node in middle\n3. Add node at the end\n0. Exit");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            printf("\nEnter the number (data):");
            scanf("%d", &num);
            pre(&head, num);
            break;
        }
        case 2:
        {
            printf("\nEnter number (data):");
            scanf("%d", &num);
            insert(head, num);
            break;
        }
        case 3:
        {
            printf("\nEnter number (data:");
            scanf("%d", &num);
            append(&head, num);
            break;
        }
        }
    } while (option != 0);
    printlist(head);
    return 0;
}