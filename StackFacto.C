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
        return 0;
    }
    else
    {
        struct NODE *j = *head;
        int h = j->data;
        *head = j->next;
        j->next = NULL;
        free(j);
        j = NULL;
        return h;
    }
}

int findfac(struct NODE *head)
{
    int j, res;
    res = 1;
    printf("\n");
    while (head != NULL)
    {
        j = pop(&head);
        res = res * j;
    }
    return res;
}
int main()
{
    struct NODE *head = NULL;
    int num;
    printf("\nEnter number whose factorial is to be found:");
    scanf("%d", &num);
    if (num > 0)
    {
        while (num > 0)
        {
            head = push(head, num);
            num--;
        }
    }
    else
    {
        printf("\nCannot find!");
    }
    printf("The factorial of the number is:");
    printf("%d", findfac(head));
    return 0;
}