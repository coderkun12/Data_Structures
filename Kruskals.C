#include <stdio.h>
#include <stdlib.h>

static int store[30];
int numver;

// FOR ADJECENT LIST
struct adj
{
    int value, weight;
    struct adj *next;
};

// FOR VERTICES LIST
struct vertex
{
    int value;
    struct adj *head;
    struct vertex *next;
};

// FOR A GRAPH OBJECT THIS FUNCTION IS DEFINED
struct graph
{
    struct vertex *vhead;
} obj;

// TO CREATE A LINKED LIST ARRAY
struct Node
{
    int wei, v, u;
    struct Node *next;
};

// INSERTION SORT
struct Node *sortedInsert(struct Node *head_ref, struct Node *new_node)
{
    struct Node *current = head_ref;
    if (current == NULL)
    {
        new_node->next = new_node;
        head_ref = new_node;
        return head_ref;
    }
    else if (current->wei >= new_node->wei)
    {
        while (current->next != head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = head_ref;
        head_ref = new_node;
        return head_ref;
    }
    else
    {
        while (current->next != head_ref &&
               current->next->wei < new_node->wei)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
        return head_ref;
    }
}

// CREATES A ARRAY
struct Node *create_node(struct Node *head, int v, int u, int weight)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->u = u;
    new_node->v = v;
    new_node->wei = weight;
    head = sortedInsert(head, new_node);
    return head;
}

// CREATES THE LL FOR ADJECENTS OF A VERTEX
struct adj *create_adj(struct adj *head, int value, int weight)
{
    struct adj *new_node = (struct adj *)malloc(sizeof(struct adj));
    new_node->value = value;
    new_node->weight = weight;
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

// CREATES VERTICES LINKEDLIST
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

// FOR FINDING THE VALUE AT GIVEN LOCATION IN BELONGS ARRAY
int find(int belongs[], int vertexn)
{
    return (belongs[vertexn]);
}

// FOR APPLYING UNION
void applyunion(int a, int b, int belongs[], int rank[])
{
    if (rank[a] == rank[b])
    {
        belongs[b] = belongs[a];
        rank[b] = rank[b] + 1;
    }
    else if (rank[a] > rank[b])
    {
        belongs[b] = belongs[a];
        rank[a] = rank[a] + 1;
    }
    else if (rank[b] > rank[a])
    {
        belongs[a] = belongs[b];
        rank[b] = rank[b] + 1;
    }
    else
        ;
}

// KRUSKALS ALGORITHM
void kruskals(struct Node *h)
{
    int i, n1, n2, sum = 0;
    int belongs[30], rank[30];
    for (i = 0; i < numver; i++)
    {
        belongs[i] = i;
        rank[i] = -1;
    }
    struct Node *t = h;
    n1 = find(belongs, t->u);
    n2 = find(belongs, t->v);
    sum += t->wei;
    printf("\n%d\t-\t%d\t==\t%d", store[t->u], store[t->v], t->wei);
    applyunion(t->u, t->v, belongs, rank);
    t = t->next;
    while (t != h)
    {
        n1 = find(belongs, t->u);
        n2 = find(belongs, t->v);
        if (n1 != n2)
        {
            sum += t->wei;
            printf("\n%d\t-\t%d\t==\t%d", store[t->u], store[t->v], t->wei);
            applyunion(t->u, t->v, belongs, rank);
        }
        else if (n1 == n2)
            ;
        else
            ;
        t = t->next;
    }
    printf("\nThe minimum cost of spanning tree is:%d", sum);
}

// TO FIND INDEX OF THE GIVEN VERTICE IN ARRAY
int find_index(int a)
{
    int i = 0;
    while (i < numver)
    {
        if (store[i] == a)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{
    int i, value, n, w, h;
    struct Node *head = NULL;
    obj.vhead = NULL;
    printf("----------KRUSKALS ALGORITHM FOR MINIMUM SPANNING TREE----------");
    printf("\nEnter number of vertices:\t");
    scanf("%d", &numver);
    for (i = 0; i < numver; i++)
    {
        printf("Enter the value of Vertex %d:\t", i + 1);
        scanf("%d", &value);
        obj.vhead = create_ver(obj.vhead, i);
        store[i] = value;
    }
    struct vertex *j = obj.vhead;
    printf("\nEnter the adjecents of vertices:\n");
    while (j != NULL)
    {
        j->head = NULL;
        printf("\nEnter the number of adjecents of vertex %d:\t", store[j->value]);
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("Enter %d adjecent :\t", i + 1);
            scanf("%d", &value);
            h = find_index(value);
            printf("Enter the weight:\t");
            scanf("%d", &w);
            j->head = create_adj(j->head, value, w);
            head = create_node(head, j->value, h, w);
        }
        j = j->next;
    }
    printf("---SET OF VERTICES---\t---Weight---");
    kruskals(head);
    return 0;
}