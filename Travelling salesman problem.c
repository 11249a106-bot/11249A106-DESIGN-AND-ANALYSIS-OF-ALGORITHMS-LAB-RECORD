#include <stdio.h>
#include <limits.h>

int n, cost[10][10], visited[10];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int city, int count) {
    int i, min_cost = INT_MAX, temp;
    if (count == n && cost[city][0] > 0)
        return cost[city][0];

    visited[city] = 1;

    for (i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] > 0) {
            temp = cost[city][i] + tsp(i, count + 1);
            min_cost = min(min_cost, temp);
        }
    }

    visited[city] = 0;
    return min_cost;
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;

    int result = tsp(0, 1);

    printf("Minimum tour cost: %d\n", result);

    return 0;
}