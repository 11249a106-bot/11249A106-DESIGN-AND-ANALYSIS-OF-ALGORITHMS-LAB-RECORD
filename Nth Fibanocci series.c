#include <stdio.h>
int fib_rec(int n) {
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}
int fib_iter(int n) {
    int a = 0, b = 1, c, i;

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Recursive Fibonacci: %d\n", fib_rec(n));
    printf("Iterative Fibonacci: %d\n", fib_iter(n));

    return 0;
}