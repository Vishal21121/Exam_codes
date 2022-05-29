#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5

int min_find(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void print_all(int graph[V][V], int parent[])
{
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d-%d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void prims(int graph[V][V])
{
    int key[V];
    int parent[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        mstSet[i] = false;
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        int u = min_find(key, mstSet);
        mstSet[u] = true;

        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] && mstSet[i] == false && graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    print_all(graph, parent);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prims(graph);

    return 0;
}