#include <stdio.h>
#include <stdlib.h>
struct adj
{
    int value;
    struct adj *next;
};
struct vertex
{
    int value;
    struct adj *head;
    struct vertex *next;
};
struct graph
{
    struct vertex *vhead;
} obj;
struct adj *create_adj(struct adj *head, int value)
{
    struct adj *new_node = (struct adj *)malloc(sizeof(struct adj));
    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    struct adj *k = head;
    while (k->next != NULL)
    {
        k = k->next;
    }
    k->next = new_node;
    return head;
}
struct vertex *create_ver(struct vertex *head, int value)
{
    struct vertex *new_node = (struct vertex *)malloc(sizeof(struct vertex));
    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    struct vertex *k = head;
    while (k->next != NULL)
    {
        k = k->next;
    }
    k->next = new_node;
    return head;
}
void printlist(struct vertex *hea)
{
    printf("\nThe Linked List representation is as follows:\n");
    while (hea != NULL)
    {
        printf("%d->", hea->value);
        while (hea->head != NULL)
        {
            printf("%d->", hea->head->value);
            hea->head = hea->head->next;
        }
        printf("NULL");
        hea = hea->next;
        printf("\n");
    }
}
int main()
{
    int i, numver, value, n;
    obj.vhead = NULL;
    printf("----------LINKED LIST IMPLEMENTATION OF GRAPH----------");
    printf("\nEnter number of vertices:\t");
    scanf("%d", &numver);
    for (i = 0; i < numver; i++)
    {
        printf("Enter the value of Vertex %d:\t", i + 1);
        scanf("%d", &value);
        obj.vhead = create_ver(obj.vhead, value);
    }
    struct vertex *j = obj.vhead;
    printf("\nEnter the adjecents of vertices:\n");
    while (j != NULL)
    {
        j->head = NULL;
        printf("\nEnter the number of adjecents of vertex %d:\t", j->value);
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("Enter adjecent %d:\t", i + 1);
            scanf("%d", &value);
            j->head = create_adj(j->head, value);
        }
        j = j->next;
    }
    printlist(obj.vhead);
    return 0;
}