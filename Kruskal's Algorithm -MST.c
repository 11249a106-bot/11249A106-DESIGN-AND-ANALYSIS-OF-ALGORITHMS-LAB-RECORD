#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Edge {
    int u, v, w;
};

int parent[MAX];


int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


void union_set(int u, int v) {
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

int main() {
    int n, i, j, e = 0;
    int cost[MAX][MAX];
    struct Edge edges[MAX * MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] != 0 && i < j) {
                edges[e].u = i;
                edges[e].v = j;
                edges[e].w = cost[i][j];
                e++;
            }
        }
    }

    
    qsort(edges, e, sizeof(edges[0]), compare);

    
    for (i = 0; i < n; i++)
        parent[i] = i;

    int count = 0, total = 0;

    printf("Edges in MST:\n");

    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d -> %d : %d\n", u, v, edges[i].w);
            total += edges[i].w;
            union_set(u, v);
            count++;
        }
    }

    printf("Total cost of MST = %d\n", total);

    return 0;
}