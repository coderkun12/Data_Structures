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
int getnew(struct NODE *head)
{
    int h;
    struct NODE *y = head;
    h = y->data + y->next->data;
    return h;
}
int pop(struct NODE **head)
{
    int h;
    if (*head == NULL)
    {
        printf("Stack empty!");
        return 0;
    }
    else
    {
        struct NODE *j = *head;
        h = j->data;
        *head = j->next;
        j->next = NULL;
        free(j);
        j = NULL;
        return h;
    }
}
static void reverse(struct NODE **head_ref)
{
    struct NODE *prev = NULL;
    struct NODE *current = *head_ref;
    struct NODE *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void printlist(struct NODE *head, int lim)
{
    int u, i;
    i = 0;
    reverse(&head);
    while (head != NULL || i < lim)
    {
        u = pop(&head);
        printf("%d ", u);
        i++;
    }
}
int main()
{
    struct NODE *head = NULL;
    int num, m, i;
    printf("\nEnter number of terms in fibonacci series you wish to print:\t");
    scanf("%d", &num);
    head = push(head, 1);
    head = push(head, 1);
    i = 0;
    while (i < (num - 2))
    {
        m = getnew(head);
        head = push(head, m);
        i++;
    }
    printlist(head, num);
    return 0;
}