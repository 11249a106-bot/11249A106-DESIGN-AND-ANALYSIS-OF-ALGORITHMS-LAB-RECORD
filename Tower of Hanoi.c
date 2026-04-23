#include <stdio.h>

void tower(int n, char from, char to, char aux)
{
    if (n <= 0)
        return;

    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    tower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower(n - 1, aux, to, from);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of disks\n");
        return 0;
    }

    tower(n, 'A', 'C', 'B');

    return 0;
}