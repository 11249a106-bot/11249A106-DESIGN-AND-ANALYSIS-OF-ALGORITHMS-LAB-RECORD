#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1, j, temp;

        for (j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int pi = i + 1;

        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}
int binarySearch(int a[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[N], i, key, result;
    clock_t start, end;
    srand(time(0));
    for (i = 0; i < N; i++)
        a[i] = rand() % 10000;

    
    quicksort(a, 0, N - 1);
    key = rand() % 10000;
    printf("Key to search: %d\n", key);

    start = clock();
    result = binarySearch(a, 0, N - 1, key);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found\n");

    printf("Time taken for binary search: %lf seconds\n", time_taken);

    return 0;
}