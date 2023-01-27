#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
struct NODE *enQ(struct NODE *head, int n)
{
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        printf("\nThe queue is full!");
        return head;
    }
    else
    {
        new_node->data = n;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
            return head;
        }
        else
        {
            struct NODE *tra = head;
            while (tra->next != NULL)
            {
                tra = tra->next;
            }
            tra->next = new_node;
            new_node->next = NULL;
            return head;
        }
    }
}
struct NODE *deQ(struct NODE *head)
{
    if (head == NULL)
    {
        printf("\nThe Queue is empty!");
        return head;
    }
    else
    {
        struct NODE *temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
        return head;
    }
}
void printlist(struct NODE *head)
{
    struct NODE *h = head;
    printf("\n");
    if (head == NULL)
    {
        printf("The list is empty!");
    }
    else
    {
        while (h != NULL)
        {
            printf("%d\t", h->data);
            h = h->next;
        }
    }
}
int main()
{
    struct NODE *head = NULL;
    int num, opt;
    printf("--------Perform Operations on Queue now----------");
    do
    {
        printf("\nWhich operation do you wish to perform? Enter option number:\n1. Add element to Queue\n2. Delete element from Queue\t");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("\nEnter element:\t");
            scanf("%d", &num);
            head = enQ(head, num);
            break;
        }
        case 2:
        {
            head = deQ(head);
            break;
        }
        default:
            break;
        }
    } while (opt != 0);
    printf("\nThe existing element in the Queue are:");
    printlist(head);
    return 0;
}