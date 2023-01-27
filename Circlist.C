#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
struct NODE *addnode(struct NODE *head, int num, int pos)
{
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        printf("FAIL");
    }
    new_node->data = num;
    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
        return head;
    }
    if (pos == 1)
    {
        struct NODE *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
        return head;
    }
    else if (pos == -1)
    {
        struct NODE *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
        return head;
    }
    else
    {
        struct NODE *temp = head;
        struct NODE *temp2;
        int i;
        for (i = 1; i < pos; i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
        new_node->next = temp;
        temp2->next = new_node;
        return head;
    }
}
struct NODE *delnode(struct NODE *head, int opt)
{
    struct NODE *g = head;
    struct NODE *f;
    if (head == NULL)
    {
        printf("\nList empty!\n");
        return head;
    }
    // DEL AT BEG
    if (opt == 1)
    {
        f = head;
        while (f->next != head)
        {
            f = f->next;
        }
        f->next = head->next;
        head = head->next;
        g->next = NULL;
        free(g);
        f = NULL;
        return head;
    }
    // DEL AT END
    else if (opt == -1)
    {
        while (g->next != head)
        {
            f = g;
            g = g->next;
        }
        f->next = head;
        g->next = NULL;
        free(g);
        g = NULL;
        return head;
    }
    else
    {
        int i;
        for (i = 1; i < opt; i++)
        {
            f = g;
            g = g->next;
        }
        f->next = g->next;
        g->next = NULL;
        free(g);
        g = NULL;
        return head;
    }
}
void printlist(struct NODE *n)
{
    printf("\n");
    struct NODE *j = n;
    printf("%d\t", j->data);
    j = j->next;
    while (j != n)
    {
        printf("%d\t", j->data);
        j = j->next;
    }
}
int main()
{
    struct NODE *head = NULL;
    int num, opt, pos, opt2;
    printf("------------- Lets create a circular linked list -------------\n");
    do
    {
        printf("\nEnter appropriate option:\n1. Add node\t2.Delete node\t0. Exit\t");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("\nEnter element you wish to add to node:\t");
            scanf("%d", &num);
            printf("\n1. Add at beginning\t2. Add at end\t3. Add at nth position\t");
            scanf("%d", &opt2);
            if (opt2 == 1)
            {
                head = addnode(head, num, 1);
            }
            else if (opt2 == 2)
            {
                head = addnode(head, num, -1);
            }
            else if (opt2 == 3)
            {
                printlist(head);
                printf("\nEnter position:");
                scanf("%d", &pos);
                head = addnode(head, num, pos);
            }
            break;
        }
        case 2:
        {
            printf("\nWhere do you wish to delete the node:\n1.At beginning\t2. From end\t3. At nth Position\t");
            scanf("%d", &opt2);
            if (opt2 == 1)
            {
                head = delnode(head, 1);
            }
            else if (opt2 == 2)
            {
                head = delnode(head, -1);
            }
            else if (opt2 == 3)
            {
                printf("\nThe existing list is:");
                printlist(head);
                printf("\nEnter the position which you wish to delete:\t");
                scanf("%d", &pos);
                head = delnode(head, pos);
            }
            break;
        }
        default:
            break;
        }
    } while (opt != 0);
    printf("\n-------The elements in the list are-------");
    printlist(head);
    return 0;
}