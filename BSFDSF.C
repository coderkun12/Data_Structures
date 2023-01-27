#include <stdio.h>
#include <stdlib.h>
#define V 4

int BSFout[12];
int DSFout[12];

int vertices1[V];
int vertices2[V];

static int b = 0, d = 0;
static int n1 = 0, n2 = 0;

struct stack
{
    int data;
    struct stack *next;
};
struct stack *push(struct stack *head, int num)
{
    struct stack *new_node = (struct stack *)malloc(sizeof(struct stack));
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
int pop(struct stack **head)
{
    int y;
    if (*head == NULL)
    {
        printf("Stack empty!");
        return NULL;
    }
    else
    {
        struct stack *j = *head;
        y = j->data;
        *head = j->next;
        j->next = NULL;
        free(j);
        j = NULL;
        return y;
    }
}
int isempty(struct stack *j)
{
    if (j == NULL)
    {
        return 0;
    }
    return 1;
}
struct Q
{
    struct Q *next;
    int data;
};
struct Q *addQ(struct Q *head, int data)
{
    struct Q *new_node = (struct Q *)malloc(sizeof(struct Q));
    if (new_node == NULL)
    {
        printf("\nThe queue is full!");
        return head;
    }
    else
    {
        new_node->data = data;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
            return head;
        }
        else
        {
            struct Q *tra = head;
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
int isEmptyQ(struct Q *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1;
}
int deQ(struct Q **head)
{
    int h;
    if (*head == NULL)
    {
        printf("\nThe Queue is empty!");
        return -1;
    }
    else
    {
        struct Q *temp = *head;
        h = temp->data;
        *head = temp->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
        return h;
    }
}
int checkav(int k)
{
    int i;
    for (i = 0; i < n1; i++)
    {
        if (vertices1[i] == k)
        {
            return 1;
        }
    }
    return 0;
}
void DSF(int graph[V][V], int a)
{
    struct stack *head = NULL;
    head = push(head, a);
    int i, j, m;
    i = 0;
    while (i < V)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                head = push(head, graph[i][j]);
            }
            else
                ;
        }
        i++;
    }
    while (isempty(head) == 1)
    {
        m = pop(&head);
        if (checkav(m) == 0)
        {
            vertices1[n1] = m;
            DSFout[d] = m;
            n1++;
            d++;
        }
        else
            ;
    }
}
int checkev(int k)
{
    int i;
    for (i = 0; i < n2; i++)
    {
        if (vertices2[i] == k)
        {
            return 1;
        }
    }
    return 0;
}
void BSF(int graph[V][V], int a)
{
    struct Q *head = NULL;
    head = addQ(head, a);
    int i, j, m;
    i = 0;
    while (i < V)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                head = addQ(head, graph[i][j]);
            }
            else
                ;
        }
        i++;
    }
    while (isEmptyQ(head) == 1)
    {
        m = deQ(&head);
        if (checkev(m) == 0)
        {
            vertices2[n2] = m;
            BSFout[b] = m;
            n2++;
            b++;
        }
        else
            ;
    }
}
int main()
{
    int m, i, v, u;
    int value[V];
    int graph[V][V] = {0};
    printf("----------Breadth First Search/Depth First Search----------");
    printf("\nEnter number of edges: ");
    scanf("%d", &m);
    printf("\nEnter the nomenclature of Vertices:\n");
    for (i = 0; i < V; i++)
    {
        scanf("%d", &value[i]);
    }
    printf("\nThe values associated with the index of matrix is:\n");
    for (i = 0; i < V; i++)
    {
        printf("%d-%d\n", i, value[i]);
    }
    for (i = 0; i < m; i++)
    {
        printf("\nEnter Vertices for edge %d:\t", i + 1);
        scanf("%d %d", &v, &u);
        graph[u][v] = value[v];
        graph[v][u] = value[u];
    }
    printf("\nEnter the starting vertex for traversal:\t");
    scanf("%d", &v);
    BSF(graph, value[v]);
    printf("\nBreadth First Search traversal of graph starting from %d vertex is:\n", v);
    for (i = 0; i < b; i++)
    {
        printf("%d\t", BSFout[i]);
    }
    DSF(graph, value[v]);
    printf("\nDepth First Search traversal of graph starting from %d vertex:\n", v);
    for (i = 0; i < d; i++)
    {
        printf("%d\t", DSFout[i]);
    }
    return 0;
}