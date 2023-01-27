#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
struct NODE *push(struct NODE *head, int num)
{
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        printf("\nStack full!");
    }
    else
    {
        new_node->data = num;
        new_node->next = head;
        head = new_node;
        return head;
    }
}
int pop(struct NODE **head)
{
    if (*head == NULL)
    {
        printf("Stack empty!");
        return NULL;
    }
    else
    {
        struct NODE *j = *head;
        int g = j->data;
        *head = j->next;
        j->next = NULL;
        free(j);
        j = NULL;
        return g;
    }
}
void printlist(struct NODE *head)
{
    int mo;
    while (head != NULL)
    {
        mo = pop(&head);
        printf("%d", mo);
    }
}
int main()
{
    struct NODE *head = NULL;
    int num, remain;
    printf("Enter the number which is to be converted to binary: ");
    scanf("%d", &num);
    while (num > 1)
    {
        remain = num % 2;
        head = push(head, remain);
        num = num / 2;
    }
    head = push(head, num);
    printf("The numbers binary equivalent is: ");
    printlist(head);
    return 0;
}