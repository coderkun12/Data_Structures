#include <stdio.h>
#define V 5
static int n = 0;
static int g = 0;
static int tree_wt = 0;
int vertices[V];

struct weights
{
    int v1, v2;
    int weight;
} weight[50];

void add_vertice(int h)
{
    vertices[n] = h;
    n++;
}

int check(int k)
{
    int i;
    for (i = 0; i < V; i++)
    {
        if (vertices[i] == k)
        {
            return 1;
        }
    }
    return 0;
}

void add_weight(int a, int b, int c)
{
    weight[g].v1 = a;
    weight[g].v2 = b;
    weight[g].weight = c;
    g++;
}

int check_wt(int l)
{
    int i;
    for (i = 0; i < g; i++)
    {
        if (l >= weight[i].weight)
        {
            l = i;
        }
    }
    return l;
}

void primMST(int gr[V][V])
{
    int f, i, j, temp, wt, v1, v2;
    for (i = 0; i < V; i++)
    {
        temp = 10000;
        for (j = 0; j < V; j++)
        {
            if (gr[i][j] < temp && gr[i][j] != 0)
            {
                v1 = i;
                v2 = j;
                temp = gr[i][j];
            }
            else if (gr[i][j] != 0)
            {
                add_weight(i, j, gr[i][j]);
            }
        }
        f = check_wt(temp);
        if (f != temp)
        {
            v1 = weight[f].v1;
            v2 = weight[f].v2;
            temp = weight[f].weight;
            weight[f].weight = 10000;
        }
        else
        {
            temp = f;
        }
        if (check(v1) == 1 && check(v2) == 1)
            ;
        else
        {
            if (check(v1) == 0)
            {
                add_vertice(v1);
            }
            if (check(v2) == 0)
            {
                add_vertice(v2);
            }
            tree_wt += temp;
            printf("\n(%d-%d)\t\t%d", v1, v2, temp);
        }
    }
    printf("\nMinimum weight= %d", tree_wt);
}

int main()
{
    int m, i, v, u, w;
    int graph[V][V] = {0};
    printf("----------PRIMS ALGORITHM (MINIMUM SPANNING TREE)----------");
    printf("\nEnter number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        printf("\nEnter Vertices for edge %d:\t", i);
        scanf("%d %d", &v, &u);
        printf("\nEnter weight of the edge:\t");
        scanf("%d", &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    printf("\nVertices\tWeight");
    primMST(graph);
    return 0;
}