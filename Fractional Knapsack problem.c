#include <stdio.h>

int main() {
    int n, i, j;
    float w[10], p[10], ratio[10], temp, capacity, profit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input weights and profits
    for (i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%f %f", &w[i], &p[i]);

        if (w[i] == 0) {
            printf("Weight cannot be zero.\n");
            return 0;
        }

        ratio[i] = p[i] / w[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort by profit/weight ratio (descending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weights
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                // Swap profits
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Fractional Knapsack logic
    for (i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (w[i] <= capacity) {
            profit += p[i];
            capacity -= w[i];
        } else {
            profit += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", profit);

    return 0;
}