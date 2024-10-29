#include <stdio.h>


int fib(int n);

int main() {
    int n;
    printf("Enter a Number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        int result = fib(n);
        printf("Fibonacci of %d is %d\n", n, result);
    }

    return 0;
}

int fib(int n) {

    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}
