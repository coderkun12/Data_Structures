#include <stdio.h>
#include <stdlib.h>

/* structure for a node */
struct Node
{
    int data;
    struct Node *next;
};
struct Node *sortedInsert(struct Node *head_ref, struct Node *new_node)
{
    struct Node *current = head_ref;

    // Case 1 of the above algo
    if (current == NULL)
    {
        new_node->next = new_node;
        head_ref = new_node;
        return head_ref;
    }
    // Case 2 of the above algo
    else if (current->data >= new_node->data)
    {
        /* If value is smaller than head's value then
        we need to change next of last node */
        while (current->next != head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = head_ref;
        head_ref = new_node;
        return head_ref;
    }
    // Case 3 of the above algo
    else
    {
        /* Locate the node before the point of insertion */
        while (current->next != head_ref &&
               current->next->data < new_node->data)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
        return head_ref;
    }
}
/* Function to print nodes in a given linked list */
void printList(struct Node *start)
{
    struct Node *u = start;
    printf("%d\t", start->data);
    u = u->next;
    while (u != start)
    {
        printf("%d\t", u->data);
        u = u->next;
    }
}
/* Driver program to test above functions */
int main()
{
    int list_size, num, opt;
    /* start with empty linked list */
    struct Node *start = NULL;
    struct Node *temp;
    do
    {
        printf("\nEnter the number:\t");
        scanf("%d", &num);
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = num;
        start = sortedInsert(start, temp);
        printf("\nDo you wish to continue adding? Y:1 N:0");
        scanf("%d", &opt);
    } while (opt != 0);
    printList(start);
    return 0;
}