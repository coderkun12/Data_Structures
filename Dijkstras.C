#include <stdio.h>
#include <stdlib.h>
#define V 10
static int g = 0;
int graph[V][V] = {0};
static int vertices[10];
static int lengths[10];
static int checkarray[10];
static int num_ver;
int check(int f)
{
    int i;
    for (i = 0; i < g; i++)
    {
        if (checkarray[i] == 1)
        {
            return 1;
        }
    }
    return 0;
}
int min_dist()
{
    int min = INT_MAX;
    int min_index, i;
    for (i = 0; i < num_ver; i++)
    {
        if (check(i) == 0 && lengths[i] < min)
        {
            min = lengths[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstras(int s)
{
    int i, j, minval = INT_MAX;
    int marked = 0, minidx;
    for (i = 0; i < num_ver; i++)
    {
        lengths[i] = INT_MAX;
    }
    lengths[s] = 0;
    for (i = 0; i < num_ver - 1; i++)
    {
        int u = min_dist();
        checkarray[u] = 1;
        for (j = 0; j < num_ver; j++)
        {
            if (check(j) == 0 && graph[u][j] != 0)
            {
                if (lengths[u] != INT_MAX && graph[u][j] + lengths[u] < lengths[j])
                {
                    lengths[j] = lengths[u] + graph[u][j];
                }
            }
        }
    }
    printf("\nShortest distances are as follows:\n");
    for (i = 0; i < num_ver; i++)
    {
        printf("\n");
        printf("%d-%d\t%d", vertices[s], vertices[i], lengths[i]);
    }
}
int find_index(int k, int a)
{
    int i;
    for (i = 0; i < k; i++)
    {
        if (vertices[i] == a)
        {
            return i;
        }
    }
}
int main()
{
    int mm, i, j, weight, source, destination, num_edges;
    printf("----------Dijkstra's Algortihm----------");
    printf("\nEnter number of vertices:\t");
    scanf("%d", &num_ver);
    if (num_ver > 10)
    {
        exit(0);
    }
    else
    {
        printf("\nEnter the values of the vertices:\n");
        for (i = 0; i < num_ver; i++)
        {
            scanf("%d", &vertices[i]);
        }
        printf("\nEnter number of edges:\t");
        scanf("%d", &num_edges);
        for (i = 0; i < num_edges; i++)
        {
            printf("Enter the source vertex of %d edge:\t", i + 1);
            scanf("%d", &source);
            printf("Enter destination vertex of %d edge:\t", i + 1);
            scanf("%d", &destination);
            printf("Enter weight of %d edge:\t", i + 1);
            scanf("%d", &weight);
            graph[find_index(num_ver, source)][find_index(num_ver, destination)] = weight;
            graph[find_index(num_ver, destination)][find_index(num_ver, source)] = weight;
        }
        printf("\nThe adjecency matrix represetation is as follows:");
        for (i = 0; i < num_ver; i++)
        {
            printf("\n");
            for (j = 0; j < num_ver; j++)
            {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\nEnter the source vertex from whom the distance is to be calclulated:\t");
        scanf("%d", &mm);
        dijkstras(find_index(num_ver, mm));
    }
    return 0;
}