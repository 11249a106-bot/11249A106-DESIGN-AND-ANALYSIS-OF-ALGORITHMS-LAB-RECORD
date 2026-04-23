#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;


int bfs(int rGraph[MAX][MAX], int s, int t, int parent[]) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[t];
}


int maxFlow(int graph[MAX][MAX], int s, int t) {
    int u, v;
    int rGraph[MAX][MAX];
    int parent[MAX];
    int max_flow = 0;

    
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int graph[MAX][MAX];
    int s, t, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter capacity matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source and sink: ");
    scanf("%d %d", &s, &t);

    printf("Maximum flow: %d\n", maxFlow(graph, s, t));

    return 0;
}