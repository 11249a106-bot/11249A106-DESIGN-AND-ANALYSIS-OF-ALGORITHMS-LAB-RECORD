#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ls(int a1[], int begin, int stop, int search)
{
    if (begin >= stop)
        printf("Element not found\n");
    else if (a1[begin] == search)
        printf("Element found at position %d\n", begin + 1);
    else
        ls(a1, begin + 1, stop, search);
}

int main()
{
    int a[10000], n = 10000, key, i;
    clock_t start, end;

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    key = rand() % 1000;

    start = clock();
    ls(a, 0, n, key);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total time taken for execution is %lf seconds\n", time_taken);

    return 0;
}