#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, src;
    int cost[10][10], dist[10], visited[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INT_MAX;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    
    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    
    for (i = 1; i < n; i++) {
        int min = INT_MAX, u = -1;

        // Find minimum distance vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break; 

        visited[u] = 1;

        
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INT_MAX &&
                dist[u] != INT_MAX &&
                dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> %d = INF\n", src, i);
        else
            printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}