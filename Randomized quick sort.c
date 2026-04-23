#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i]; 
            a[i] = a[j]; 
            a[j] = temp;
        }
    }

    temp = a[i + 1]; 
    a[i + 1] = a[high]; 
    a[high] = temp;

    return i + 1;
}

int random_partition(int a[], int low, int high) {
    int r = low + rand() % (high - low + 1);

    int temp = a[r]; 
    a[r] = a[high]; 
    a[high] = temp;

    return partition(a, low, high);
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pi = random_partition(a, low, high);

        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main() {
    int n, i;
    int a[20];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(0));

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}